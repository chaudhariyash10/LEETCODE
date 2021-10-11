#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        vector<vector<int>> ans;

        if (mat.size() == 0)
            return mat;
        int m = mat.size(), n = mat[0].size();

        int perRow = (m * n) / r;

        int x = 0, y = 0;

        for (int i = 0; i < r; i++)
        {
            vector<int> temp;
            for (int j = 0; j < perRow; j++)
            {
                temp.push_back(mat[x][y]);

                y++;
                if (y >= n)
                {
                    y = 0;
                    x++;
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};