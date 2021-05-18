#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int query(vector<vector<int>> &arr, int minR, int minC, int maxR, int maxC)
    {
        return arr[maxR][maxC] - arr[minR - 1][maxC] - arr[maxR][minC - 1] + arr[minR - 1][minC - 1];
    };
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> ans(mat.size());
        if (mat.size() == 0 || mat[0].size() == 0)
            return ans;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> arr(mat.size() + 1);

        for (int i = 0; i < n + 1; i++)
        {
            arr[i].push_back(0);
        }
        for (int i = 0; i < m + 1; i++)
        {
            arr[0].push_back(0);
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                arr[i].push_back(mat[i - 1][j - 1] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // int minR = max(0, i - k);
                // int maxR = min(n - 1, i + k);
                // int minC = max(0, j - k);
                // int maxC = min(m - 1, j + k);
                int temp = query(arr, max(0, i - k) + 1, max(0, j - k) + 1, min(n - 1, i + k) + 1, min(m - 1, j + k) + 1);
                ans[i].push_back(temp);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<vector<int>> ans = s.matrixBlockSum(mat, 1);
    // cout << "Run";
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << " ";
        }
    }
}