#include <stdc++.h>

using namespace std;

map<int, list<int>> adj;

void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y];
}

bool isCyclic(int v, bool visited[], bool * recStack)
{
    if(!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for(int i : adj[v])
        {
            if(!visited[i] && isCyclic(i, visited, recStack))
                return true;
            else if(recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    for (int i = 0; i < prerequisites.size(); i++)
    {
        addEdge(prerequisites[i][1], prerequisites[i][0]);
    }

    bool *visited = new bool[numCourses];
    bool *recStack = new bool[numCourses];

    for (int i = 0; i < numCourses; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (pair<int, list<int>> cur : adj)
        if(isCyclic(cur.first , visited, recStack))
            return false;
    
    return true;
}