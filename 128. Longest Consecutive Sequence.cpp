#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> umap;

        for (int i = 0; i < nums.size(); i++)
            umap[nums[i]] = true;

        for (int i = 0; i < nums.size(); i++)
            if (umap[nums[i] - 1])
                umap[nums[i]] = false;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = 1;

            while (umap[nums[i] + cur])
                cur++;

            ans = max(ans, cur);
        }

        return ans;
    }
};