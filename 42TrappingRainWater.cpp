#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int size = height.size();
        int left[size];
        int right[size];

        int maxLeft = 0;
        for (int i = 0; i < size; i++)
        {
            left[i] = maxLeft;

            maxLeft = max(maxLeft, height[i]);
        }

        int maxRight = 0;
        int area = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            right[i] = maxRight;
            maxRight = max(maxRight, height[i]);

            int temp = min(right[i], left[i]) - height[i];
            if (temp > 0)
                area += temp;
        }
        return area;
    }
};