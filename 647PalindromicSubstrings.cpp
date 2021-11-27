#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     int countSubstrings(string s)
//     {
//         int n = s.size();
//         vector<vector<bool>> dp(n, vector<bool>(n));
//         int cnt = 0;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 // cout << i << " " << j << endl;
//                 dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
//
//                 if (dp[i][j])
//                     cnt++;
//             }
//         }
//
//         return cnt;
//     }
// };

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int j = i, k = i;

            while (j >= 0 && k < n)
            {
                if (s[j] == s[k])
                    count++;
                else
                    break;
                j--, k++;
            }

            j = i - 1, k = i;

            while (j >= 0 && k < n)
            {
                if (s[j] == s[j])
                    count++;
                else
                    break;

                j--, k++;
            }
        }

        return count;
    }
};

int main()
{
    string s = "abc";

    Solution k;
    cout << k.countSubstrings(s);
}