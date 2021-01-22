#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSegments(string s)
    {
        if (s.size() < 1)
        {
            return s.size();
        }

        if (s.size() == 1)
        {
            if (s[0] == ' ')
                return 0;
            else
                return 1;
        }

        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                while (s[i] == ' ' && i < s.size())
                {
                    i++;
                }
            }
            else if(s[i] != ' ')
            {
                count++;
                while (s[i] != ' ' && i < s.size())
                {
                    i++;
                }   
            }
        }
            return count;
    }
};
