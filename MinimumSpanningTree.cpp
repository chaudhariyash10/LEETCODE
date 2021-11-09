#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V);
        // vector<bool> visited(V, false);
        set<pair<int, int>> s;
        vector<bool> visited(V, false);

        dist[0] = 0;
        parent[0] = -1;
        s.insert({0, 1});

        for (int i = 1; i < V; i++)
            s.insert({INT_MAX, i});

        while (!s.empty())
        {

            int par = (s.begin())->second;
            visited[par] = true;

            for (int i = 0; i < adj[par].size(); i++)
            {
                if (!visited[adj[par][i][0]])
                    if (dist[adj[par][i][0]] > dist[par] + adj[par][i][1])
                    {
                        s.erase(s.find({dist[adj[par][i][0]], adj[par][i][0]}));
                        dist[adj[par][i][0]] = dist[par] + adj[par][i][1];
                        s.insert({dist[adj[par][i][0]], adj[par][i][0]});
                    }
            }
        }
        int ans = 0;

        for (int i = 0; i < V; i++)
        {
            ans += dist[i];
        }

        return ans;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    int i = 0;
    vector<vector<int>> adj[V];

    while (i++ < E)
    {
        int u, w;
        cin >> u >> w;
        vector<int> t1, t2;

        
    }
}