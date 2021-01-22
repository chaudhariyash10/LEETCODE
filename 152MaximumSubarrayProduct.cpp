#include <stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if(nums.size() == 1)
            return nums[0];
        int maxPro = nums[0], curPro = nums[0], minPro = nums[0], curMin = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int tmp = nums[i] * curPro;
            curPro = max(curPro * nums[i], nums[i]);
            curPro = max(curPro, minPro * nums[i]);
            maxPro = max(maxPro, curPro);

            minPro = min(nums[i], minPro * nums[i]);
            minPro = min(tmp, minPro );
        }   
        return maxPro;
    }
};
