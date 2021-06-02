#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        bool dp[s.size() + 1][p.size() + 1];

        dp[0][0] = true;
        // cout << " Case 1" << endl;
        for (int i = 1; i <= p.size(); i++)
            if (dp[0][i - 1] == true && p[i - 1] == '*')
                dp[0][i] = true;
            else
                dp[0][i] = false;

        // cout << " Case 2" << endl;
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i][0] = false;
        }
        // cout << " Case 3" << endl;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (s[i - 1] == p[j - 1] && dp[i - 1][j - 1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }

        return dp[s.size()][p.size()];
    }
};

int main()
{
    Solution S;
    string s = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab";
    string p = "***bba**a*bbba**aab**b";

    cout << S.isMatch(s, p);
}