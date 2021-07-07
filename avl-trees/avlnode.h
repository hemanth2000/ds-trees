class AVLNode
{

public:
    int val;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    ~AVLNode()
    {
        delete left;
        delete right;
    }
};