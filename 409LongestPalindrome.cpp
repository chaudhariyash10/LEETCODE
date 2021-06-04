#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int cap[26], small[26];

        for (int i = 0; i < 26; i++)
            cap[i] = small[i] = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] > 96)
                small[s[i] - 97]++;
            else
                cap[s[i] - 65]++;
        }
        int palLength = 0;

        // for(int i = 0)
        for (int i = 0; i < 26; i++)
        {
                palLength += cap[i] / 2 * 2;
                palLength += small[i] / 2 *2 ;
        }

        if (palLength < s.size())
            palLength++;

        return palLength;
    }
};

int main()
{
    string s = "abccccdd";
    Solution So;
    cout << So.longestPalindrome(s);
}