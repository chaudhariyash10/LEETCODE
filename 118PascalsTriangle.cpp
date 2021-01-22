#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generate(vector<vector<int>> &ans, int rows, int curRow)
{
    if (rows <= curRow)
        return;

    for (int i = 1; i < curRow; i++)
    {
        ans[curRow][i] = ans[curRow - 1][i - 1] + ans[curRow - 1][i];
    }

    generate(ans, rows, curRow + 1);
}

//Recursion
vector<vector<int>> pascalRec(int rows)
{
    vector<vector<int>> ans(rows);

    for (int i = 0; i < rows; i++)
    {
        ans[i].resize(i+1);
        ans[i][0] = 1;
        ans[i][i] = 1;
    }

    if (rows < 3)
        return ans;

    generate(ans, rows, 2);

    return ans;
}

//Iteration
vector<vector<int>> pascalIter(int rows)
{
    vector<vector<int>> ans(rows);

    for (int i = 0; i < rows; i++)
    {

        ans[i].resize(i + 1);

        ans[i][0] = ans[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    return ans;
}

int main()
{
    cout << "Enter No of Rows: ";
    int rows;
    cin >> rows;
    cout << endl;

    vector<vector<int>> res = pascalRec(rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}