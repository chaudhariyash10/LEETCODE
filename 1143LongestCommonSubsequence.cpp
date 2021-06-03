#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string s, string p)
    {
        int dp[s.size() + 1][p.size() + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[s.size()][p.size()];
    }
};