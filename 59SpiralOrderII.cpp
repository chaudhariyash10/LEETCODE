#include <stdc++.h>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    
    vector<vector<int>> ans(n);
    if (n == 0)
        return ans;

    for (int i = 0; i < n; i++)
        ans[i].resize(n);

    int rowUp = 0, rowDown = n - 1, colLeft = 0, colRight = n - 1,input = 1 ;
    int dir = 0;

    while (rowUp <= rowDown && colLeft <= colRight)
    {
        if (dir % 4 == 0)
        {
            for (int i = colLeft; i <= colRight; i++)
                ans[rowUp][i] = input++;
            rowUp++;
        }

        else if (dir % 4 == 1)
        {
            for (int i = rowUp; i <= rowDown; i++)
                ans[i][colRight] = input++;
            colRight--;
        }

        else if (dir % 4 == 2)
        {
            for (int i = colRight; i >= colLeft; i--)
                ans[rowDown][i] = input++;
            rowDown--;
        }
        else if (dir % 4 == 3)
        {
            for (int i = rowDown; i >= rowUp; i--)
                ans[i][colLeft] = input++;
            colLeft++;
        }
        dir++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ans[i][j] = ans[i][j];
    }

        return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans = generateMatrix(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
