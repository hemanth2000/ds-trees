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
};