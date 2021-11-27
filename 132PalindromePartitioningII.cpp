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
    }
};