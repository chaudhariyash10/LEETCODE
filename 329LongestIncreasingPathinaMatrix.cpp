#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(vector<vector<int>> &mat, vector<vector<int>> &dp, int i, int j, int n, int m)
    {
        if (dp[i][j] != 0)
            return;
        dp[i][j] = 1;
        // cout << i << " " << j << endl;
        if (i + 1 < n && mat[i + 1][j] > mat[i][j])
        {
            if (dp[i + 1][j] == 0)
                helper(mat, dp, i + 1, j, n, m);

            dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j]);
        }

        if (j + 1 < m && mat[i][j + 1] > mat[i][j])
        {
            if (dp[i][j + 1] == 0)
                helper(mat, dp, i, j + 1, n, m);
            dp[i][j] = max(dp[i][j], 1 + dp[i][j + 1]);
        }

        if (i - 1 >= 0 && mat[i - 1][j] > mat[i][j])
        {
            if (dp[i - 1][j] == 0)
                helper(mat, dp, i - 1, j, n, m);
            dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j]);
        }

        if (j - 1 >= 0 && mat[i][j - 1] > mat[i][j])
        {
            if (dp[i][j - 1] == 0)
                helper(mat, dp, i, j - 1, n, m);
            dp[i][j] = max(dp[i][j], 1 + dp[i][j - 1]);
        }
    }
    int longestIncreasingPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        if (n == 0)
            return 0;
        int m = mat[0].size();

        // vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> dp(n, vector<int>(m));

        int maxLength = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout << i << " " << j << endl;
                if (dp[i][j] == 0)
                {
                    helper(mat, dp, i, j, n, m);
                }
                if (maxLength < dp[i][j])
                    maxLength = dp[i][j];
            }
        }
        // for (auto i : dp)
        // {
        //     for (auto j : i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        return maxLength;
    }
};

int main()
{
    vector<vector<int>> mat{
        {9, 9, 4}, {6, 6, 8}, {2, 1, 1}};

    Solution s;
    cout << s.longestIncreasingPath(mat);
}