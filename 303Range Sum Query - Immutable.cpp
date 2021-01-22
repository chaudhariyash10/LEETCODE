#include <bits/stdc++.h>
using namespace std;

class NumArray
{
    vector<int> prefix;

public:
    NumArray(vector<int> &nums)
    {
        prefix.push_back(0);

        if (nums.size() > 0)
        {
            prefix.push_back(nums[0]);

            for (int i = 1; i < nums.size(); i++)
            {
                prefix.push_back(prefix[i] + nums[i]);
            }
        }
    }

    int sumRange(int i, int j)
    {
        return (prefix[j+1] - prefix[i]);
    }
};