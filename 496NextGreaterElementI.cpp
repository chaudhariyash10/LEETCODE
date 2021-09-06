#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        map<int, int> mp;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                mp[nums2[i]] = -1;
                s.push(nums2[i]);
            }
            else if (s.top() > nums2[i])
            {
                mp[nums2[i]] = s.top();
                s.push(nums2[i]);
            }
            else if (s.top() < nums2[i])
            {
                while (!s.empty() && s.top() < nums2[i])
                    s.pop();
                int element = s.empty() ? -1 : s.top();
                mp[nums2[i]] = element;
                s.push(nums2[i]);
            }
        }

        vector<int> res;
        for (int i = 0; i < nums1.size(); i++)
            res.push_back(mp[nums1[i]]);

        return res;
    }
};