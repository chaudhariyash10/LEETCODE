#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() <= 1)
            return 0;

        int maxProfitSoFar = 0;
        int minPriceSoFar = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            maxProfitSoFar = max(maxProfitSoFar, prices[i] - minPriceSoFar);
            if(minPriceSoFar > prices[i])
                minPriceSoFar = prices[i];
        }
        return maxProfitSoFar;
    }
};
