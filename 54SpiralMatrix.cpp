#include <stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &v)
{
    vector<int> ans;

    if (v.empty())
        return ans;
    int rowUp = 0, rowDown = v.size() - 1, colRight = v[0].size() - 1, colLeft = 0, input = 1;
    int dir = 0;

    while (rowUp <= rowDown && colLeft <= colRight)
    {
        if (dir % 4 == 0)
        {
            for (int i = colLeft; i <= colRight; i++)
                ans.push_back(v[rowUp][i]);
            rowUp++;
        }

        else if (dir % 4 == 1)
        {
            for (int i = rowUp; i <= rowDown; i++)
                ans.push_back(v[i][colRight]);
            colRight--;
        }

        else if (dir % 4 == 2)
        {
            for (int i = colRight; i >= colLeft; i--)
                ans.push_back(v[rowDown][i]);
            rowDown--;
        }
        else if (dir % 4 == 3)
        {
            for (int i = rowDown; i >= rowUp; i--)
                ans.push_back(v[i][colLeft]);
            colLeft++;
        }
        dir++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> v{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    vector<int> ans = spiralOrder(v);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}