#include <bits/stdc++.h>
using namespace std;

#define print(x) cout << #x << " " << x << endl;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        // cout << "it"
        //      << " " << *(lower_bound(arr.begin(), arr.end(), x));
        int j = idx + 1, i = idx;
        int count = 0;
        // print(idx);
        while (count < k)
        {
            if (j >= arr.size())
            {
                ans.push_back(arr[i]);
                i--;
            }
            else if (i < 0)
            {
                ans.push_back(arr[j]);
                j++;
            }
            else if (abs(arr[j] - x) < abs(arr[i] - x))
            {
                ans.push_back(arr[j]);
                j++;
            }
            else
            {
                ans.push_back(arr[i]);
                i--;
            }
            count++;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr{0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
    vector<int> ans;
    ans = s.findClosestElements(arr, 3, 5);

    for (auto i : ans)
        cout << i << " ";
}