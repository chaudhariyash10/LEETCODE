#include <stdc++.h>

using namespace std;

// bool isRowValid(vector<vector<char>> &board, int r)
// {
//     unordered_map<char, bool> umap;

//     for (int i = 0; i < 9; i++)
//     {
//         if (board[r][i] == '.')
//             continue;
//         if (umap[board[r][i]])
//         {
//             return false;
//         }
//         else
//         {
//             umap[board[r][i]] = true;
//         }
//     }

//     return true;
// }
// bool isColumnValid(vector<vector<char>> &board, int c)
// {
//     unordered_map<char, bool> umap;

//     for (int i = 0; i < 9; i++)
//     {
//         if (board[i][c] == '.')
//             continue;

//         if (umap[board[i][c]])
//         {
//             return false;
//         }
//         else
//         {
//             umap[board[i][c]] = true;
//         }
//     }

//     return true;
// }

// bool isSquareValid(vector<vector<char>> &board, int r, int c)
// {
//     unordered_map<char, bool> umap;

//     for (int i = r - 1; i < r + 2; i++)
//     {
//         for (int j = c - 1; j < c + 2; j++)
//         {
//             if (board[i][j] == '.')
//                 continue;

//             if (umap[board[i][j]])
//             {
//                 return false;
//             }
//             else
//             {
//                 umap[board[i][j]] = true;
//             }
//         }
//     }

//     return true;
// }

// bool isValidSudoku(vector<vector<char>> &board)
// {
//     bool ans = true;

//     for (int i = 0; i < 9; i++)
//     {
//         ans = (isRowValid(board, i) && isColumnValid(board, i));

//         if (!ans)
//             return ans;
//     }

//     for (int i = 1; i < 9; i = i + 3)
//     {
//         ans = (isSquareValid(board, i, 1) && isSquareValid(board, i, 4) && isSquareValid(board, i, 7));
//         if (!ans)
//             return ans;
//     }

//     return ans;
// }

//Improved Solution:

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_map<string, bool> seen;
    bool ans = true;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                string Row;
                Row.push_back(board[i][j]);
                Row += "seen in row" + to_string(i);

                string Column;
                Column.push_back(board[i][j]);
                Column += "seen in column" + to_string(j);

                string Box;
                Box.push_back(board[i][j]);
                Box += "seen in box" +
                      to_string(i / 3) + "-" + to_string(j / 3);

                ans = (seen[Row] || seen[Column] || seen[Box]);

                if (ans)
                    return false;

                else
                {
                    seen[Row] = true;
                    seen[Column] = true;
                    seen[Box] = true;
                }
            }
        }
    }
    return true;
}