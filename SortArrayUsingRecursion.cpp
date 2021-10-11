#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl;
class Solution
{
public:
    void insert(vector<int> &nums, int val)
    {
        if (nums.size() == 0 || nums[nums.size() - 1] >= val)
        {
            nums.push_back(val);
            return;
        }

        int temp = nums[nums.size() - 1];

        nums.pop_back();

        insert(nums, val);

        nums.push_back(temp);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return nums;

        int temp = nums[nums.size() - 1];
        // debug(temp);
        nums.pop_back();
        nums = sortArray(nums);

        insert(nums, temp);

        return nums;
    }
};

int main()
{
    vector<int> nums{3, 1, 5, 2};

    Solution s;
    nums = s.sortArray(nums);

    for (int i : nums)
        cout << i << " ";
}