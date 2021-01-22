#include <stdc++.h>

using namespace std;



int main()
{
    map<int, list<int>> adj;

    adj[2].push_back(1);
    adj[1];

    for(pair<int, list<int>> cur: adj)
    {
        cout << "vertex: " << cur.first<<"->";

        for(int i: adj[cur.first])
        {
            cout << i << " ";
        }
        cout << endl;
    }
}