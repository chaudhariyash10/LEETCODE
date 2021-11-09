#include <bits/stdc++.h>
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
    int helper(TreeNode *root, int &res)
    {
        if (root == nullptr)
            return 0;

        int l = helper(root->left, res);
        int r = helper(root->right, res);

        res = max(res, l + r + root->val);
        res = max(res, l + root->val);
        res = max(res, r + root->val);
        return max(max(l, r) + root->val, 0);
    }
    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int res = root->val;
        helper(root, res);
        return res;
    }
};