#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> cur, int i)
    {
        if( i < 0)
            return;

        if(candidates[i] == target)
        {
            cur.push_back(candidates[i]);
            ans.push_back(cur);
            
        }     


    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        helper(candidates, target, ans, cur, candidates.size() - 1);

        return ans;
    }
};