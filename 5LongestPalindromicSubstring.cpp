#include <stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int dp[n + 1][n + 1];
        string p = s;
        reverse(p.begin(), p.end());
        int longest = INT_MIN, x, y;
        string ans;
        // cout<<"Hii1"<<endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else
                {
                    if (p[j - 1] == s[i - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else
                        dp[i][j] = 0;

                    if (dp[i][j] > longest)
                    {
                        string temp = s.substr(i - dp[i][j], dp[i][j]);
                        string rev = temp;
                        reverse(temp.begin(), temp.end());
                        if (temp == rev)
                        {
                            longest = dp[i][j];
                            x = i;
                            y = j;
                            ans = temp;
                        }
                    }
                }
            }
        }
        // cout<<"Hii1"<<endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        // cout<<"Hii1"<<endl;

        // cout << x << " " << y << endl;
        // string ans = "";
        // int loop = dp[x][y];
        // while (loop--)
        // {
        //     ans += s[x - 1];
        //     x--;
        // }
        return ans;
    }
};
int main()
{
    string s = "abbc";
    Solution So;
    cout << So.longestPalindrome(s);
}


