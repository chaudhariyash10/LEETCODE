#include <bits/stdc++.h>
using namespace std;

// class Solution
// {

//     multiset<int, greater<int>> maxHeap;

//     void addNum(int x)
//     {
//         maxHeap.insert(x);
//     }

//     int getMax()
//     {
//         return *(maxHeap.begin());
//     }

//     void remove(int x)
//     {
//         maxHeap.erase(maxHeap.find(x));
//     }

// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         vector<int> ans;

//         if (nums.size() < 1)
//             return ans;

//         if (nums.size() == 1)
//         {
//             return nums;
//         }

//         for (int i = 0; i < k; i++)
//         {
//             addNum(nums[i]);
//         }

//         int left = 0, right = k - 1;
//         ans.push_back(getMax());

//         while (right < nums.size() - 1)
//         {
//             remove(nums[left]);
//             left++;
//             right++;
//             addNum(nums[right]);
//             ans.push_back(getMax());
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        if (nums.size() <= 1)
            return nums;

        dq.push_back(nums[0]);

        for (int i = 1; i < k; i++)
        {
            while (dq.size() > 0 && dq.back() < nums[i])
                dq.pop_back();

            dq.push_back(nums[i]);
        }

        ans.push_back(dq.front());

        int left = 0,right = k-1;

        while(right +1 < nums.size())
        {
            if(dq.size() == k)
                dq.pop_front();

            while (dq.size() > 0 && dq.back() < nums[right+1])
                dq.pop_back();

            dq.push_back(nums[right+1]);
            ans.push_back(dq.front());
            if(dq.front() == nums[left])
                dq.pop_front();
            left++;
            right++;
        }
        return ans;
    }
};