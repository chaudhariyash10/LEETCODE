
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

    unordered_map<int, int> umap;
    int n;
    int idx;

public:
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int l, int r)
    {
        if (l > r)
            return nullptr;

        TreeNode *temp = new TreeNode(preorder[idx++]);

        if (l == r)
            return temp;

        temp->left = helper(preorder, inorder, l, umap[temp->val] - 1);

        temp->right = helper(preorder, inorder, umap[temp->val] + 1, r);

        return temp;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        n = inorder.size();
        idx = 0;
        for (int i = 0; i < n; i++)
            umap[inorder[i]] = i;

        return helper(preorder, inorder, 0, n - 1);
    }
};