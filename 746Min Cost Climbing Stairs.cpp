#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        if (cost.size() == 2)
            return min(cost[0], cost[1]);

        int prevStep = cost[1];
        int prevStep2 = cost[0];

        for (int i = 2; i < cost.size(); i++)
        {
            int temp = min(prevStep + cost[i], prevStep2 + cost[i]);
            prevStep2 = prevStep;
            prevStep = temp;
        }

        return min(prevStep, prevStep2);
    }
};