#include <stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() <= 1)
            return s.length();
        int l = 0, r = 1;
        unordered_map<char, int> arr;
        arr[s[l]]++;

        int maxSize = 1, curSize = 1;
        while (r < s.length())
        {
            if (arr[s[r]] == 0)
            {
                arr[s[r]]++;
                curSize++;
                if (curSize > maxSize)
                    maxSize = curSize;
                r++;
            }
            else
            {
                while (s[r] != s[l])
                {
                    arr[s[l]]--;
                    l++;
                    curSize--;
                }
                arr[s[l]]--;
                l++;
                curSize--;
            }
        }

        return maxSize;
    }
};