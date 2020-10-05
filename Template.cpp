#include <stdc++.h>

using namespace std;

class Graph
{
    map<int, list<int>> l;

public:
    void addEdge(int u, int v);
};

void Graph::addEdge(int u, int v)
{
    l[u].push_back(v);
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
}

int main()
{
}