#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> solve(vector<int> &nums, int n)
    {
        // cout << nums[n] << " ";
        if (n == -1)
        {
            vector<vector<int>> temp;
            vector<int> k;
            temp.push_back(k);
            return temp;
        }
        vector<vector<int>> temp = solve(nums, n - 1);
        int size = temp.size();
        for (int i = 0; i < size; i++)
        {
            vector<int> temp1 = temp[i];
            temp1.push_back(nums[n]);
            temp.push_back(temp1);
        }

        // vector<int> temp1{nums[n]};
        // temp.push_back(temp1);

        //         cout << "n: " << n << endl;
        //
        //         for (auto i : temp)
        //         {
        //             for (auto j : i)
        //             {
        //                 cout << j << " ";
        //             }
        //             cout << endl;
        //         }
        //         cout << "end: " << n << endl;
        return temp;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;

        ans = solve(nums, nums.size() - 1);

        return ans;
    }
};

int main()
{
    vector<int> temp1{1, 2, 3, 4};

    Solution s;

    vector<vector<int>> x = s.subsets(temp1);

    for (auto i : x)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}