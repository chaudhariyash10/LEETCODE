#include <stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void preOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        cout << root->val;
        preOrder(root->left);
        preOrder(root->right);
    }

    TreeNode *helper(TreeNode *prevNode, TreeNode *nextNode)
    {

    }

    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (root->left)
          root =  helper(root, root->left);
    }
};