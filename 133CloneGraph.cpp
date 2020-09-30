#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<int, bool> umap;
    map<int, Node *> Map;

    void dfs(Node * node)
    {
        if(umap[node->val])
            return;

        umap[node->val] = true;

        Map[node->val] = new Node(node->val);

        for(auto i: node->neighbors)
            dfs(i);

        for(auto i: node -> neighbors)
        {
            Map[node->val]->neighbors.push_back(Map[i->val]);
        }    
    }

    Node *cloneGraph(Node *node)
    {
        if(node == nullptr)
        {
            return node;
        }

        dfs(node);

        return Map[1];
    }
};

int main()
{
}