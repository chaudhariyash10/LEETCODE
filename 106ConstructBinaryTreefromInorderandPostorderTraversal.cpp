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
    unordered_map<int, int> umap;
    int idx;

    TreeNode *helper(vector<int> &postorder, int l, int r)
    {
        if (l > r)
            return nullptr;

        TreeNode *temp = new TreeNode(postorder[idx--]);

        if (l == r)
            return temp;

        temp->right = helper(postorder, umap[temp->val] + 1, r);
        temp->left = helper(postorder, l, umap[temp->val] - 1);

        return temp;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        idx = inorder.size() - 1;

        umap.clear();

        for (int i = 0; i < inorder.size(); i++)
            umap[inorder[i]] = i;

        return helper(postorder, 0, inorder.size() - 1);
    }
};