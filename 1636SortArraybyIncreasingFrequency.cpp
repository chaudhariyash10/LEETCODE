
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class comparator
    {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if (a.second == b.second)
                return a < b;
            return a.second > b.second;
        }
    };
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int i : nums)
            mp[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

        for (pair<int, int> p : mp)
        {
            pq.push(p);
        }

        vector<int> ans;

        while (pq.size())
        {
            pair<int, int> i = pq.top();

            while (mp[i.first])
            {
                ans.push_back(i.first);
                mp[i.first]--;
            }
            pq.pop();
        }

        return ans;
    }
};