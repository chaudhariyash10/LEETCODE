#include <stdc++.h>

using namespace std;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int numIslands(vector<vector<int>> &v)
{
    if (v.empty())
        return 0;
    int ans = 0;
    queue<pair<int, int>> q;
    unordered_map<pair<int, int>, bool, hash_pair> umap;

    int i = 0, j = 0;

    q.push({i, j});

    while (!q.empty())
    {
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            pair<int, int> temp = q.front();
            int curI = temp.first;
            int curJ = temp.second;

            if (umap[{curI, curJ}] != true)
            {
                if (v[curI][curJ] == 1)
                {
                  ans++;
                  
                }
                if (curI - 1 >= 0)
                {
                    q.push({curI - 1, curJ});
                    if (v[curI][curJ] == 1 && v[curI - 1][curJ] == 1)
                    {
                        umap[{curI - 1, curJ}] = true;
                    }
                }

                if (curI + 1 < v.size())
                {
                    q.push({curI + 1, curJ});
                    if (v[curI][curJ] == 1 && v[curI + 1][curJ] == 1)
                    {
                        umap[{curI + 1, curJ}] = true;
                    }
                }

                if (curJ - 1 >= 0)
                {
                    q.push({curI, curJ - 1});
                    if (v[curI][curJ] == 1 && v[curI][curJ - 1] == 1)
                    {
                        umap[{curI, curJ - 1}] = true;
                    }
                }
                if (curJ + 1 < v[curI].size())
                {
                    q.push({curI, curJ + 1});
                    if (v[curI][curJ] == 1 && v[curI][curJ + 1] == 1)
                    {
                        umap[{curI, curJ + 1}] = true;
                    }
                }
            }

            q.pop();
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> v = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};

    cout << numIslands(v);
}