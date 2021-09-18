#include <stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     class comparator
//     {
//     public:
//         bool operator()(pair<int, int> p1, pair<int, int> p2)
//         {
//             return p1.second < p2.second;
//         }
//     };
//
//     vector<int> topKFrequent(vector<int> &nums, int k)
//     {
//         priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
//         unordered_map<int, int> mp;
//
//         for (int i = 0; i < nums.size(); i++)
//         {
//                 mp[nums[i]]++;
//
//         }
//
//         for (pair<int, int> p : mp)
//         {
//             pq.push(p);
//         }
//         vector<int> ans;
//         for (int i = 0; i < k; i++)
//         {
//             pair<int, int> p = pq.top();
//             pq.pop();
//             ans.push_back(p.first);
//         }
//
//         return ans;
//     }
// };

class Solution
{
public:
    class comparator
    {
    public:
        bool operator()(pair<int, int> p1, pair<int, int> p2)
        {
            return p1.second > p2.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue < pair<int, int>, vector<pair<int, int>>, comparator> pq;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for (pair<int, int> p : mp)
        {
            pq.push(p);

            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (pq.size())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.first);
        }

        return ans;
    }
};