#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        queue<TreeNode *> que;

        if (root == NULL)
            return res;

        que.push(root);

        while (que.size() > 0)
        {
            vector<int> v;
            int size = que.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = que.front();
                v.push_back(temp->val);
                que.pop();

                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }

            res.push_back(v);
        }

        return res;
    }
};