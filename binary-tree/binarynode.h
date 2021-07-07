class BinaryNode
{

public:
    int val;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(int x)
    {
        this->val = x;
        left = nullptr;
        right = nullptr;
    }

    BinaryNode(int x, BinaryNode *left, BinaryNode *right)
    {
        this->val = x;
        this->left = left;
        this->right = right;
    }

    ~BinaryNode()
    {
        delete left;
        delete right;
    }
};