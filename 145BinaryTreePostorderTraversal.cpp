#include <stdc++.h>

using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST
{
public:
    TreeNode *root;
    BST()
    {
        this->root = nullptr;
    }
};

TreeNode *insert(TreeNode *root, int val)
{

    if (root == nullptr)
    {
        TreeNode *temp = new TreeNode(val);
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

vector<int> helper(TreeNode *root, vector<int> pre)
{
    if (root == nullptr)
    {
        return pre;
    }

    
    pre = helper(root->left, pre);
    pre = helper(root->right, pre);
    pre.push_back(root->val);

    return pre;
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> pre;

    pre = helper(root, pre);

    return pre;
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

    vector<int> pre = postorderTraversal(tree.root);

    for (auto i : pre)
    {
        cout << i << " ";
    }
}