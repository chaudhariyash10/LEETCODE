#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans;
    void helper(int col, int &n, vector<string> &board, vector<bool> &row, vector<bool> &left, vector<bool> &right)
    {
        if (col == n)
        {
            ans++;
            return;
        }

        else
        {
            for (int i = 0; i < n; i++)
            {
                if (row[i] == 0 && left[i + col] == 0 && right[n - 1 + col - i] == 0)
                {
                    board[i][col] = 'Q';
                    row[i] = true;
                    left[i + col] = true;
                    right[n - 1 + col - i] = true;

                    helper(col + 1, n, board, row, left, right);

                    board[i][col] = '.';
                    row[i] = false;
                    left[i + col] = false;
                    right[n - 1 + col - i] = false;
                }
            }
        }
    }
    int solveNQueens(int n)
    {
        vector<bool> row(n, false), left(2 * n + 1, false), right(2 * n + 1, false);
        ans = 0;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        helper(0, n, board, row, left, right);

        return ans;
    }
};