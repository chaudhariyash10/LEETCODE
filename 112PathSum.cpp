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

void helper(TreeNode *root, int sum, int runningSum, bool &ans)
{   

    if (root->left == nullptr && root->right == nullptr && runningSum + root->val == sum)
       { 
           ans = true;
           return;
       }
    
        if( root -> left)
        helper(root->left, sum, runningSum + root->val, ans);
       if(root -> right)
         helper(root->right, sum, runningSum + root->val, ans);
}

bool hasPathSum(TreeNode *root, int sum)
{   
    if(root == nullptr)
        return false;
        
    bool ans = false;

    helper(root, sum, 0, ans);

    return ans;
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

    bool ans = hasPathSum(tree.root, 12);

    cout << ans;
}
