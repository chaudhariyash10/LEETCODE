#include <stdc++.h>

using namespace std;

class TreeNode
{

public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree
{

public:
    TreeNode *root;
    BinaryTree()
    {
        root = nullptr;
    }
};

TreeNode *insert(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        root = new TreeNode(x);
        return root;
    }
    else
    {
        if (root->val <= x)
        {
            root->right = insert(root->right, x);
        }
        else
        {
            root->left = insert(root->left, x);
        }
    }
    return root;
}

TreeNode *findMin(TreeNode *root)
{
    if (root->right == nullptr)
        return root;

    else
    {
       return findMin(root->right);
    }
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

TreeNode *deleteNode(TreeNode *root, int x)
{
    if (root == nullptr)
        return root;
    else if (x < root->val)
    {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->val)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }

        else if (root->left == nullptr)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            TreeNode *mini = findMin(root->right);
            root->val = mini->val;
            root->right = deleteNode(root->right, root->val);
        }
    }
    return root;
}
int main()
{
    BinaryTree *tree = new BinaryTree();

    tree->root = insert(tree->root, 3);
    tree->root = insert(tree->root, 4);
    tree->root = insert(tree->root, 1);
    tree->root = insert(tree->root, 2);
    tree->root = insert(tree->root, 6);
    tree->root = insert(tree->root, -1);
    tree->root = insert(tree->root, 25);
    tree->root = insert(tree->root, 10);

    inorder(tree->root);
    cout << endl;
    tree->root = deleteNode(tree->root, -1);
    inorder(tree->root);
}