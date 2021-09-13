#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});
        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> cur = q.front();
            q.pop();

            mp[cur.second.second][cur.second.first].insert(cur.first->val);

            if (cur.first->left)
                q.push({cur.first->left, {cur.second.first + 1, cur.second.second - 1}});
            if (cur.first->right)
                q.push({cur.first->right, {cur.second.first + 1, cur.second.second + 1}});
        }

        for (pair<int, map<int, multiset<int>>> x : mp)
        {
            vector<int> v;

            for (pair<int, multiset<int>> y : x.second)
            {
                for (int i : y.second)
                {
                    v.push_back(i);
                }
            }

            ans.push_back(v);
        }

        return ans;
    }
};