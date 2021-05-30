#include <bits/stdc++.h>
using namespace std;

//MAtrix Block Sum
// class Solution
// {
// public:
//     int countSquares(vector<vector<int>> &mat)
//     {
//         int n = mat.size();
//         int m = mat[0].size();
//         // cout << n << " " << m << endl;
//         vector<vector<int>> pre(mat.size() + 1);
//         for (int i = 0; i < n + 1; i++)
//             pre[i].push_back(0);
//         for (int i = 0; i < m + 1; i++)
//             pre[0].push_back(0);
//
//         int count = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 pre[i].push_back(mat[i - 1][j - 1] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1]);
//
//                 if (mat[i - 1][j - 1] == 1)
//                     count++;
//             }
//         }
//         // cout << "Hii" << endl;
//         // return pre;
//         for (int k = 2; k <= min(n, m); k++)
//         {
//             for (int i = 0; i < n - k + 1; i++)
//             {
//                 for (int j = 0; j < m - k + 1; j++)
//                 {
//                     int r = i + 1, c = j + 1;
//                     if (k * k == pre[r + k - 1][c + k - 1] - pre[r + k - 1][c - 1] - pre[r - 1][c + k - 1] + pre[r - 1][c - 1])
//                         count++;
//                 }
//             }
//             // cout << "K: " << k << endl;
//             // ;
//         }
//
//         return count;
//     }
// };

class Solution
{
public:
    int countSquares(vector<vector<int>> &mat)
    {
        int count = 0;

        vector<vector<int>> pre(mat.size() + 1);
        for (int i = 0; i < mat.size() + 1; i++)
            pre[i].push_back(0);
        for (int i = 0; i < mat[0].size() + 1; i++)
            pre[0].push_back(0);

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    pre[i + 1].push_back(min(min(pre[i][j + 1], pre[i][j]), pre[i + 1][j]) + 1);
                    count += pre[i + 1][j + 1];
                }
                else
                {
                    pre[i + 1].push_back(0);
                }
            }
        }
//         cout << endl;
// 
//         for (int i = 0; i < mat.size() + 1; i++)
//         {
//             for (int j = 0; j < mat[0].size() + 1; j++)
//             {
//                 cout << pre[i][j] << " ";
//             }
//             cout << endl;
//         }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat{
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}};
    int ans = s.countSquares(mat);
    // cout << "Run";
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << endl;
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    // }
    cout << ans;
}