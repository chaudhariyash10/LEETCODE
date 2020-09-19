
//Index starts from 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> generate(vector<int> prev, int curRow, int rows)
{
    if (curRow > rows + 1)
        return prev;

    else
    {
        vector<int> cur(curRow);
        cur[0] = 1;
        cur[curRow - 1] = 1;
        for (int i = 1; i < curRow - 1; i++)
        {
            cur[i] = prev[i - 1] + prev[i];
        }

        return generate(cur, curRow + 1, rows);
    }
}
//Recusrion
vector<int> pascalRec(int row)
{
    if (row == 0)
    {
        vector<int> v{1};
        return v;
    }
    vector<int> v1{1, 1};
    if (row == 1)
        return v1;

    return generate(v1, 2, row);
}
//Iterative

vector<int> pascalIter(int row)
{
    vector<int> prev{1};
    if (row == 0)
    {

        return prev;
    }
    vector<int> curr{1, 1};
    if (row == 1)
        return curr;

    for (int i = 2; i <= row; i++)
    {
        prev.resize(curr.size());

        prev = curr;

        curr.resize(row + 1);

        curr[0] = 1;
        curr[i] = 1;

        for (int j = 1; j < i; j++)
        {
            curr[j] = prev[j-1] + prev[j];
        }
    }

    return curr;
}
int main()
{
    int row;
    cin >> row;

    vector<int> ans = pascalIter(row);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }
}