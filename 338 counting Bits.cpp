#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res;

        for (int i = 0; i <= num; i++)
        {
            int count = 0, n = i;

            while (n > 0)
            {
                count++;
                n = n & (n - 1);
            }
            res.push_back(count);
        }
        return res;
    }
};