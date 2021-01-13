#include <stdc++.h>
using namespace std;

class Solution
{
    multiset<int, greater<int>> minHeap, maxHeap;
    void add(int num)
    {
        if (maxHeap.size() < 1)
        {
            maxHeap.insert(num);
        }
        else
        {
            multiset<int>::iterator itr = maxHeap.end();
            itr--;
            int minInMaxHeap = *itr;

            if (num > minInMaxHeap)
            {
                maxHeap.insert(num);
            }
            else
            {
                minHeap.insert(num);
            }

            if (maxHeap.size() > minHeap.size() + 1)
            {
                itr = maxHeap.end();
                itr--;
                int temp = *itr;
                maxHeap.erase(itr);
                minHeap.insert(temp);
            }

            else if (maxHeap.size() < minHeap.size())
            {
                itr = minHeap.begin();
                int temp = *itr;
                minHeap.erase(itr);
                maxHeap.insert(temp);
            }
        }
    }

    double findMedian(int k)
    {
        if (k % 2 == 1)
        {
            multiset<int>::iterator itr = maxHeap.end();
            itr--;
            return (double)*itr;
        }
        else
        {
            multiset<int>::iterator itr = maxHeap.end(), itr2 = minHeap.begin();
            itr--;
            return ((*itr + (double)*itr2) / 2);
        }
    }

    void remove(int num)
    {
        if (num <= *(minHeap.begin()) && minHeap.size() > 0)
        {
            minHeap.erase(minHeap.find(num));
        }
        else
        {
            maxHeap.erase(maxHeap.find(num));
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> res;
        if (nums.size() < 1)
            return res;

        if (nums.size() == 1)
        {
            res.push_back(nums[0]);
            return res;
        }

        maxHeap.insert(nums[0]);
        for (int i = 1; i < k; i++)
        {
            add(nums[i]);
        }

        int left = 1, right = k;
        res.push_back(findMedian(k));

        while (right < nums.size())
        {
            remove(nums[left - 1]);
            add(nums[right]);
            res.push_back(findMedian(k));
            left++;
            right++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2};
    vector<double> res = sol.medianSlidingWindow(nums, 1);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i];
}