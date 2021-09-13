#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{

public:
    vector<string> helper(string digits, vector<string> ans, vector<string> &letters, int i)
    {
        if (i == -1)
            return ans;
        vector<string> temp;

        string x = to_string(digits[i]);
        string cur = letters[stoi(x)];

        if (ans.size() == 0)
        {
            for (char j : cur)
            {
                string a(1, j);
                temp.push_back(a);
            }
        }
        else
        {
            for (int j = 0; j < cur.size(); j++)
            {
                for (string k : ans)
                {
                    temp.push_back(cur[j] + k);
                }
            }
        }

        cout << i << " :";

        for (string j : temp)
            cout << j << " ";
        cout << endl;

        return helper(digits, temp, letters, i - 1);
    }
    vector<string> letterCombinations(string digits)
    {

        vector<string> ans;

        if (digits.size() == 0)
            return ans;
        vector<string> letters{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return helper(digits, ans, letters, digits.size() - 1);
    }
};