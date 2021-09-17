#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        this->pq = pq;
        this->k = k;

        while (this->pq.size() > k)
            this->pq.pop();
    }

    int add(int val)
    {
        pq.push(val);

        while (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};
