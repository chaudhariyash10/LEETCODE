#include <bits/stdc++.h>
using namespace std;

// Matrix Chain multiplication=======================================================================================

//
// class Solution
// {
// public:
//     bool isPalindrome(string s, int i, int j)
//     {
//         if (i == j)
//             return true;
//
//         while (i < j)
//             if (s[i] != s[j])
//                 return false;
//             else
//                 i++, j--;
//
//         return true;
//     }
//     int helper(string s, int i, int j, vector<vector<int>> &dp)
//     {
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         int mini = INT_MAX;
//
//         if (isPalindrome(s, i, j))
//             return dp[i][j] = 0;
//
//         if (i >= j)
//             return dp[i][j] = 0;
//
//         for (int k = i; k < j; k++)
//         {
//             int temp1 = 0, temp2 = 0;
//
//             if (dp[i][k] != -1)
//                 temp1 = dp[i][k];
//             else
//                 temp1 = helper(s, i, k, dp);
//
//             if (dp[k + 1][j] != -1)
//                 temp2 = dp[k + 1][j];
//             else
//                 temp2 = helper(s, k + 1, j, dp);
//
//             mini = min(mini, temp1 + temp2 + 1);
//         }
//         return dp[i][j] = mini;
//     }
//     int minCut(string s)
//     {
//         vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
//         return helper(s, 0, s.size() - 1, dp);
//     }
// };

//=========================================================================================================

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                if (s[i] == s[j] && ((j - i <= 2) || (dp[i + 1][j - 1])))
                    dp[i][j] = true;

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        vector<int> cuts(n, 0);

        for (int i = 0; i < n; i++)
        {
            int cut = i;
            for (int j = 0; j <= i; j++)
            {
                if (dp[j][i])
                    cut = min(cut, j == 0 ? 0 : cuts[j - 1] + 1);
            }

            cuts[i] = cut;
        }
        return cuts[n - 1];
    }
};

int main()
{
    Solution S;

    cout << S.minCut("aabc");
}