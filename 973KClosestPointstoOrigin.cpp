
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double dist(int x, int y)
    {
        return x * x + y * y;
    }
    class comparator
    {
    public:
        bool operator()(pair<double, vector<int>> a, pair<double, vector<int>> b)
        {
            return a.first > b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, comparator> pq;

        for (int i = 0; i < points.size(); i++)
        {
            pq.push({dist(points[i][0], points[i][1]), points[i]});
        }

        int j = 0;
        while (j < k)
        {
            pair<double, vector<int>> p = pq.top();

            pq.pop();

            ans.push_back(p.second);
            j++;
        }
        return ans;
    }
};