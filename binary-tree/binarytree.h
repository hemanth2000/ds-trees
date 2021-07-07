#include <iostream>
#include <vector>
#include <queue>
#include "binarynode.h"

class BinaryTree
{

    BinaryNode *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

private:
    void inOrder(BinaryNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);
        std::cout << root->val << " ";
        inOrder(root->right);
    }

    void preOrder(BinaryNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        std::cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(BinaryNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->val << " ";
    }

    BinaryNode *insert(BinaryNode *root, int val)
    {
        if (root == nullptr)
        {
            BinaryNode *newNode = new BinaryNode(val);
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
        else
        {
            root->right = insert(root->right, val);
        }

        return root;
    }

    BinaryNode *deleteNode(BinaryNode *root, int val)
    {

        if (root == nullptr)
        {
            return root;
        }
        else if (root->val == val)
        {

            if (root->left)
            {
                BinaryNode *temp = root->left;
                while (temp->right)
                {
                    temp = temp->right;
                }

                temp->right = root->right;

                return root->left;
            }
            else
            {
                return root->right;
            }
        }
        else if (root->val > val)
        {
            root->left = deleteNode(root->left, val);
        }
        else if (root->val < val)
        {
            root->right = deleteNode(root->right, val);
        }

        return root;
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

    void deleteNode(int val)
    {
        root = deleteNode(root, val);
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

        BinaryNode *nullNode = new BinaryNode(-1);
        BinaryNode *lvlEnd = new BinaryNode(-2);
        std::queue<BinaryNode *> pendingNodes;

        pendingNodes.push(root);
        pendingNodes.push(lvlEnd);

        while (!pendingNodes.empty())
        {

            BinaryNode *currentNode = pendingNodes.front();
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

    ~BinaryTree()
    {
        delete root;
    }
};