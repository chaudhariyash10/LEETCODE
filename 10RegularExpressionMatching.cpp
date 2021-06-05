#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        bool dp[s.size() + 1][p.size() + 1];
        if (p.size() == 0 && s.size() == 0)
            return true;
        else if (p.size() == 0)
            return true;
        dp[0][0] = true;
        dp[0][1] = false;
        for (int i = 2; i <= p.size(); i++)
        {
            if (p[i - 1] != '*')
                dp[0][i] = false;
            else if (dp[0][i - 2] == true && p[i - 1] == '*')
                dp[0][i] = true;
            else
                dp[0][i] = false;
        }

        for (int i = 1; i <= s.size(); i++)
            dp[i][0] = false;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j - 1] == '*')
                {
                    bool first = (s[i - 1] == p[j - 2] || p[j - 2] == '.');
                    dp[i][j] = dp[i][j - 2] || (first && dp[i - 1][j]);
                }
                else if (p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    if (dp[i - 1][j - 1] && p[j - 1] == s[i - 1])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
            }
        }

        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 0; j <= p.size(); j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[s.size()][p.size()];
    }
};

int main()
{
    string s = "aa", p = "a*";
    Solution So;
    cout << So.isMatch(s, p);
}