#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
// int findTargetSumWays(vector<int>&a,int S){
//   int n=a.size();
//   int tot=0;
//   for(int i=0;i<n;i++)tot+=a[i];

//   if(tot<S)return 0;
//   if((tot+S)&1)return 0;

//   int target=(tot+S)/2;
//   int dp[n+5][target+5];

//   for(int i=0;i<=n;i++)dp[i][0]=1;
//   for(int i=1;i<=target;i++)dp[0][i]=0;

//   for(int i=1;i<=n;i++){
//     for(int sum=0;sum<=target;sum++){
//       if(a[i-1]>sum)
//       dp[i][sum]=dp[i-1][sum];
//       else
//       dp[i][sum]=dp[i-1][sum-a[i-1]]+dp[i-1][sum];
//     }
//   }

//   return dp[n][target];
// }
// };
class Solution
{
public:
    int countSubsetsWithSum(vector<int> &nums, int n, int sum)
    {
        int dp[n + 1][1001];

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 1;

        for (int i = 1; i < 1001; i++)
            dp[0][i] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int n = nums.size();
        int arrSum = 0;
        for (int i = 0; i < n; i++)
            arrSum += nums[i];

        if (S > 1000 || S > arrSum)
            return 0;

        if ((S + arrSum) % 2 != 0)
            return 0;

        int reqSum = (S + arrSum) / 2;

        return countSubsetsWithSum(nums, n, reqSum);
    }
};