#include <bits/stdc++.h>
using namespace std;

// class comparator
// {
// public:
//     bool operator()(pair<int, int> p1, pair<int, int> p2)
//     {
//         return p1.second > p2.second;
//     }
// };

int main()
{

    vector<vector<int>> mat(3, vector<int>(3));

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            mat[i][j] = i + j;
        }
    }

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // unordered_map<char, int> umap;

    // umap['a']++;
    // umap['c']++;
    // umap['d']++;
    // cout << umap['a']<<" "<<umap['f'];
    cout << "Hello World";
}