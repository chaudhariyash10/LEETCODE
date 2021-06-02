#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:


    bool canJump(vector<int> &nums)
    {

        int maxIdx = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (maxIdx >= nums.size() - 1)
                return true;

            if (maxIdx < i)
                return false;

            if (maxIdx < nums[i] + i)
                maxIdx = nums[i] + i;
        }

        //     vector<int> dp(nums.size(), -1);
        //     return helper(nums, dp, 0, nums.size() - 1);
    }
};

int main()
{
    Solution s;
    vector<int> v{2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2, 6, 4, 2, 4, 3, 0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9, 3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4, 3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5, 8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};

    cout << s.canJump(v);
}