#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int size;

    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> umap;

public:
    LRUCache(int capacity)
    {
        this->size = capacity;
    }

    int get(int key)
    {
        if (umap.find(key) == umap.end())
            return -1;

        int val = umap[key]->second;

        li.erase(umap[key]);
        li.push_front({key, val});
        umap[key] = li.begin();

        return val;
    }

    void put(int key, int value)
    {
        // cout << key << " " << value << endl;
        if (umap.find(key) == umap.end())
        {
            if (li.size() == this->size)
            {
                pair<int, int> rem = li.back();

                li.pop_back();

                umap.erase(rem.first);
                // cout << "hii" << endl;
            }
        }
        else
            umap.erase(key);

        li.push_front({key, value});
        umap[key] = li.begin();
    }
};

int main()
{
    LRUCache l(2);

    l.put(2, 1);
    l.put(2, 2);
    cout << l.get(2) << endl;
    l.put(1, 1);
    l.put(4, 1);
    // cout << "Hello" << endl;
    // cout << l.get(1) << endl;
    cout << l.get(2) << endl;
    // cout << l.get(3) << endl;
    // cout << l.get(4) << endl;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
