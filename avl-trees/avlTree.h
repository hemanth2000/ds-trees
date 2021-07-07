#include <iostream>
#include <vector>
#include <queue>
#include "avlnode.h"

class AVLTree
{
public:
    AVLNode *root;

    AVLTree()
    {
        root = nullptr;
    }

private:
    int getHeight(AVLNode *root)
    {
        if (root == nullptr)
        {
            return -1;
        }

        return root->height;
    }

    void setHeight(AVLNode *root)
    {
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int balance(AVLNode *root)
    {
        return getHeight(root->left) - getHeight(root->right);
    }

    AVLNode *leftRotate(AVLNode *parent)
    {
        AVLNode *temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;

        setHeight(parent);
        setHeight(temp);

        return temp;
    }

    AVLNode *rightRotate(AVLNode *parent)
    {
        AVLNode *temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;

        setHeight(parent);
        setHeight(temp);

        return temp;
    }

    AVLNode *insert(AVLNode *root, int val)
    {

        if (root == nullptr)
        {
            AVLNode *newNode = new AVLNode(val);
            return newNode;
        }
        else if (root->val == val)
        {
            return root;
        }

        if (root->val > val)
        {
            root->left = insert(root->left, val);
        }
        else if (root->val < val)
        {
            root->right = insert(root->right, val);
        }

        setHeight(root);

        int b = balance(root);

        // Four possible positions of new node wrt to current root node.

        if (b > 1)
        {
            if (val < root->val)
            {
                //Case 1: Left left

                return rightRotate(root);
            }
            else
            {
                // Case 2: Left right
                root->right = leftRotate(root->right);
                return rightRotate(root);
            }
        }
        else if (b < -1)
        {
            if (val > root->val)
            {
                // Case 3: Right right

                return leftRotate(root);
            }
            else
            {
                //Case 4: Right left
                root->left = rightRotate(root->left);
                return leftRotate(root);
            }
        }

        return root;
    }

    AVLNode *deleteNode(AVLNode *root, int val)
    {

        if (root == nullptr)
        {
            return root;
        }
        else if (root->val == val)
        {

            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if (root->left == nullptr)
            {

                AVLNode *temp = root->right;
                root->right = nullptr;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {

                AVLNode *temp = root->left;
                root->left = nullptr;
                delete root;
                return temp;
            }

            AVLNode *temp = root->left;

            while (temp->right)
            {
                temp = temp->right;
            }

            root->val = temp->val;
            deleteNode(root->left, root->val);
        }
        else if (root->val > val)
        {
            root->left = deleteNode(root->left, val);
        }
        else if (root->val < val)
        {
            root->right = deleteNode(root->right, val);
        }

        setHeight(root);
        int b = balance(root);

        if (b > 1)
        {

            if (balance(root->left) < 0)
            {
                root->left = leftRotate(root->left);
            }
            return rightRotate(root);
        }

        if (b < -1)
        {
            if (balance(root->right) > 0)
            {
                root->right = rightRotate(root->right);
            }

            return leftRotate(root);
        }

        return root;
    }

    void inOrder(AVLNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);
        std::cout << root->val << " ";
        inOrder(root->right);
    }

    void preOrder(AVLNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        std::cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(AVLNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->val << " ";
    }

public:
    void insert(int val)
    {
        root = insert(root, val);
    }

    void insert(std::vector<int> &vec)
    {

        for (int x : vec)
        {
            insert(x);
        }
    }

    void inOrder()
    {
        inOrder(root);
        std::cout << std::endl;
    }

    void preOrder()
    {
        preOrder(root);
        std::cout << std::endl;
    }

    void postOrder()
    {
        postOrder(root);
        std::cout << std::endl;
    }

    void lvlOrder()
    {
        if (root == nullptr)
        {
            return;
        }

        AVLNode *nullNode = new AVLNode(-1);
        AVLNode *lvlEnd = new AVLNode(-2);
        std::queue<AVLNode *> pendingNodes;

        pendingNodes.push(root);
        pendingNodes.push(lvlEnd);

        while (!pendingNodes.empty())
        {

            AVLNode *currentNode = pendingNodes.front();
            pendingNodes.pop();

            if (currentNode->val == -2)
            {
                if (!pendingNodes.empty())
                {
                    pendingNodes.push(lvlEnd);
                }
                std::cout << std::endl;
                continue;
            }

            std::cout << currentNode->val << " ";

            if (currentNode->val == -1)
            {
                continue;
            }

            if (currentNode->left)
            {
                pendingNodes.push(currentNode->left);
            }
            else
            {
                pendingNodes.push(nullNode);
            }

            if (currentNode->right)
            {
                pendingNodes.push(currentNode->right);
            }
            else
            {
                pendingNodes.push(nullNode);
            }
        }

        delete nullNode;
        delete lvlEnd;
    }

    void deleteNode(int val)
    {
        root = deleteNode(root, val);
    }

    ~AVLTree()
    {
        delete root;
    }
};