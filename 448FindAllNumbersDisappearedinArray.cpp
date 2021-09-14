#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int i = 0;

        while (i < nums.size())
        {
            if (nums[i] == i + 1)
                i++;
            else
                swap(nums[i], nums[nums[i] - 1]);
        }

        vector<int> disappeared;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 != nums[i])
                disappeared.emplace_back(i + 1);
        }

        return disappeared;
    }
};