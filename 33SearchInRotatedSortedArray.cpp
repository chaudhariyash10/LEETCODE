#include <bits/stdc++.h>

using namespace std;

// int search(vector<int> v, int target) {
//
//     if (v.size() < 1)
//         return -1;
//
//     int left = 0, right = v.size() - 1;
//
//     while (left  < right) {
//
//         int mid = left + (right - left) / 2;
//
//         if (v[right] < v[mid]) {
//             left = mid + 1;
//         }
//         else {
//             right = mid;
//         }
//     }
//
//
//     int start = left;
//
//     left = 0; right = v.size() -1;
//
//     if (target >= v[start] && target <= v[right]) {
//         left = start;
//     }
//     else
//     {
//         right = start;
//     }
//
//
//
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//
//         if (target == v[mid])
//             return mid;
//
//         else if(target < v[mid]){
//             right = mid - 1;
//         }
//         else{
//             left = mid+1;
//         }
//     }
//
//
//     return -1;
// }
//
// int main() {
//     vector<int> v ={ 4, 5, 6, 7, 0, 1, 2 };
//
//     int target = 0;
//
//     cout << search(v, target);
// }
//
//

#define debug(x) cout << #x << ": " << x << endl;

class Solution
{
public:
    int pivot(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1;
        int n = nums.size();
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[(mid + 1) % n])
                return (mid + 1) % n;

            else if (nums[mid] < nums[(mid + n - 1) % n])
                return mid;

            else if (nums[start] <= nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            // debug(mid);
            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }

        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int pivotIdx = pivot(nums);
        // debug(pivotIdx);
        int n = nums.size();
        int left = pivotIdx, right = pivotIdx;

        if (pivotIdx == -1)
            return binarySearch(nums, target, 0, nums.size());

        else
        {
            if (target > nums[nums.size() - 1])
                return binarySearch(nums, target, 0, pivotIdx);
            else
                return binarySearch(nums, target, pivotIdx, nums.size());
        }
        // return max(binarySearch(nums, target, 0, pivotIdx), binarySearch(nums, target, pivotIdx, nums.size()));
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 3, 5};
    cout << s.search(nums, 1);
}