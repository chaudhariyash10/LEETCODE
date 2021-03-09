#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int xors[arr.size() + 1];
        xors[0] = 0;
        for (int i = 1; i <= arr.size(); i++)
        {
            xors[i] = arr[i - 1] ^ xors[i-1];
        }

        vector<int> res;

        for (int i = 0; i < queries.size(); i++)
        {
            res.push_back(xors[queries[i][1]] ^ xors[queries[i][0] - 1]);
        }
        return res;
    }
};