#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortKSortedArray(vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
            return nums;
        // (nums.begin(), nums.begin() + k - 1)
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k + 1);

        // for (int i = 0; i <= k; i++)
        //     pq.push(nums[i]);
        int i = 0;
        int cur = k + 1;

        while (cur < nums.size())
        {
            nums[i] = pq.top();
            i++;
            pq.pop();

            pq.push(nums[cur]);
            cur++;
        }

        while (!pq.empty())
        {
            nums[i] = pq.top();
            i++;
            pq.pop();
        }

        return nums;
    }
};

int main()
{
    vector<int> nums{6, 5, 3, 2, 8, 10, 9};

    Solution s;

    nums = s.sortKSortedArray(nums, 3);

    for (auto x : nums)
        cout << x << " ";
}