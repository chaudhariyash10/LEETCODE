#include <stdc++.h>

using namespace std;

//Space: O(n)
//Space: O(n)
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> umap;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int req = target - nums[i];

        if (umap[req])
        {
            ans.push_back(umap[req] - 1);
            ans.push_back(i);
            return ans;
        }

        else
        {
            umap[nums[i]] = i + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    cout << ans[0] << "\t" << ans[1];
}