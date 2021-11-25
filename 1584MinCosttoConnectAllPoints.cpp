#include <bits/stdc++.h>
using namespace std;

int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                graph[i][j] = graph[j][i] = distance(points[i][0], points[i][1], points[j][0], points[j][1]);
            }
        }

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        set<pair<int, int>> s;
        dist[0] = 0;
        s.insert({0, 0});

        for (int i = 1; i < n; i++)
            s.insert({INT_MAX, i});

        while (!s.empty())
        {
            int par = (s.begin())->second;
            dist[par] = s.begin()->first;
            // cout << par << endl;
            s.erase(s.begin());
            visited[par] = true;

            for (int i = 0; i < n; i++)
            {
                if (graph[par][i] != 0 && visited[i] == false && dist[i] > graph[par][i])
                {
                    s.erase(s.find({dist[i], i}));
                    dist[i] = graph[par][i];
                    s.insert({graph[par][i], i});
                    // cout << "Ones" << endl;
                }
            }
            // cout << "New" << endl;
            // for (pair<int, int> i : s)
            // {
            //     cout << i.first << " " << i.second << endl;
            // }
        }

        int ans = 0;

        for (int i : dist)
        {
            // cout << i << " ";
            ans += i;
        }
        // cout << endl;
        return ans;
    }
};

int main()
{
    vector<vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    Solution s;
    cout << s.minCostConnectPoints(points);
}