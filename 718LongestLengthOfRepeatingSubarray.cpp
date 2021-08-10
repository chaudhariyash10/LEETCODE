#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size(), s2 = nums2.size();

        int dp[s1 + 1][s2 + 1];

        int ans = 0;

        for (int i = 0; i < s1 + 1; i++)
        {
            for (int j = 0; j < s2 + 1; j++)
            {
                if (j == 0 || i == 0)
                    dp[i][j] = 0;

                else if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (ans < dp[i][j])
                        ans = dp[i][j];
                }
                else
                    dp[i][j] = 0;
            }
        }

        return ans;
    }
};