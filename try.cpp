#include <stdc++.h>

using namespace std;

class comparator
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

int main()
{
    cout << (int)'a';

    // priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

    // pq.push(make_pair(2, 1));
    // pq.push(make_pair(20, 10));
    // pq.push(make_pair(2, 2000000));
    // pq.push(make_pair(200000, 1));
    // pq.push(make_pair(2, -1));

    // cout << pq.top().first;
    // cout << pq.top().second;
}