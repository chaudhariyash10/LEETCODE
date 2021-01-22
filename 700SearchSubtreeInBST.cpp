#include <iostream>

using namespace std;

class treeNode
{
public:
    treeNode *left;
    treeNode *right;
    int val;

    treeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST
{
public:
    treeNode *root;
    BST()
    {
        this->root = nullptr;
    }
};

treeNode *insert(treeNode *root, int val)
{

    if (root == nullptr)
    {
        treeNode *temp = new treeNode(val);
        root = temp;
    }

    else
    {
        if (root->val > val)
        {
            root->left = insert(root->left, val);
        }

        else
        {
            root->right = insert(root->right, val);
        }
    }
    return root;
}

void print(treeNode *root)
{
    if (root == nullptr)
        return;

    print(root->left);
    cout << root->val << "  ";
    print(root->right);
}

treeNode *helper(treeNode *root, int val, treeNode *res)
{
    if (root == nullptr)
        return res;

    else
    {
        if (root->val > val)
        {
            res = helper(root->left, val, res);
        }

        else if (root->val < val)
        {
            res = helper(root->right, val, res);
        }

        else
        {
            res = root;
        }
    }

    return res;
}

treeNode *searchSubtree(treeNode *root, int val)
{
    treeNode *res = nullptr;
    res = helper(root, val, res);
    return res;
}

int main()
{
    BST tree;

    tree.root = insert(tree.root, 5);
    tree.root = insert(tree.root, 3);
    tree.root = insert(tree.root, 4);
    tree.root = insert(tree.root, 8);
    tree.root = insert(tree.root, 1);
    tree.root = insert(tree.root, 10);
    tree.root = insert(tree.root, 11);

    treeNode *rs = searchSubtree(tree.root, 10);

    cout << rs->val << endl;
}