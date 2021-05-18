#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int memo[5][51];

public:
    Solution()
    {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 51; j++)
                memo[i][j] = -1;
    }

    int getIdx(char x)
    {
        if (x == 'a')
            return 1;
        if (x == 'e')
            return 2;
        if (x == 'i')
            return 3;
        if (x == 'o')
            return 4;

        return 5;
    }
    char increment(char x)
    {
        if (x == 'a')
            return 'e';
        if (x == 'e')
            return 'i';
        if (x == 'i')
            return 'o';
        if (x == 'o')
            return 'u';

        return 'z';
    }
    int helper(int n, char x)
    {
        if (memo[getIdx(x) - 1][n] != -1)
            return memo[getIdx(x) - 1][n];
        int count = 0;
        if (n == 1)
        {
            return getIdx(x);
        }

        char ch = 'a';
        while (ch <= x)
        {
            count += helper(n - 1, ch);
            ch = increment(ch);
        }

        return memo[getIdx(x) - 1][n] = count;
    }

    int countVowelStrings(int n)
    {
        if (n == 1)
            return 5;
        int count = 0;
        count += helper(n - 1, 'a');
        count += helper(n - 1, 'e');
        count += helper(n - 1, 'i');
        count += helper(n - 1, 'o');
        count += helper(n - 1, 'u');

        return count;
    }
};
