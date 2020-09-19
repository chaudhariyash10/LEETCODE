#include <stdc++.h>

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

int getMaxDepth(treeNode *root)
{
    if (root == nullptr)
        return 0;

    else
    {
        return max(getMaxDepth(root->left) + 1, getMaxDepth(root->right) + 1);
    }
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
    tree.root = insert(tree.root, 113);
    tree.root = insert(tree.root, 155);


    cout << getMaxDepth(tree.root);

}