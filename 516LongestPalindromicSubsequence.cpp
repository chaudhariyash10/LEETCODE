#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        string p = s;
        reverse(p.begin(), p.end());
        // cout << "Hii 1" << endl;

        int dp[n + 1][n + 1];
        // cout << "Hii 2" << endl;
        int longest = INT_MIN;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if(i == 0|| j == 0)
                    dp[i][j] = 0;
               else  if (s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                if (dp[i][j] > longest)
                    longest = dp[i][j];
            }
        }

        // cout << "Hii 3" << endl;

        return longest;
    }
};

int main()
{
    Solution s;
    string p = "bbbab";
    cout << s.longestPalindromeSubseq(p);
}