#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Occurence(vector<int> &nums, int target, bool firstOccurence)
    {
        int left = 0, right = nums.size();
        int pos = -1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                pos = mid;
                if (firstOccurence)
                    right = mid - 1;
                else
                    left = mid ;
            }

            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return pos;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans{Occurence(nums, target, true), Occurence(nums, target, false)};

        return ans;
    }
};