#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = size(nums), steps = 0, i = 0, maxIdx = INT_MIN, lastPos = 0;

        while (lastPos < n - 1)
        {
            maxIdx = max(maxIdx, i + nums[i]);

            if (i == lastPos)
            {
                lastPos = maxIdx;
                steps++;
            }
            i++;
        }
        return steps;
    }
};