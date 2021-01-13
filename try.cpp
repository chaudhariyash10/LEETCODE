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
    multiset<int, greater<int>> minHeap, maxHeap;

    minHeap.insert(10);
    minHeap.insert(1);
    minHeap.insert(11);
    minHeap.insert(-10);
    minHeap.insert(5);

    multiset<int>::iterator it;

    for (it = minHeap.begin(); it != minHeap.end(); it++)
        cout << *it << " ";
}