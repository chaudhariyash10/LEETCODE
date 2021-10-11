#include <bits/stdc++.h>

using namespace std;

// int helper(vector<int>& nums, int l, int h) {
//
//     if (l == h)
//         return l;
//
//     int mid = (l + h) / 2;
//
//
//
//     if (mid > 0 &&nums[mid] < nums[mid - 1])
//         return helper(nums, l, mid-1);
//
//     else if (mid < nums.size()-1 && nums[mid] < nums[mid+1])
//         return helper(nums, mid+ 1, h);
//
//     else
//         return mid;
// }
//
// int findPeakElement(vector<int>& nums) {
//
//     return helper(nums, 0, nums.size() -1);
// }

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1])
                right = mid - 1;
            else if (mid < n - 1 && nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                return mid;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v{2, 1};

    cout << s.findPeakElement(v);
}