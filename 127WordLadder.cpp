#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> visited{beginWord}, dict(wordList.begin(), wordList.end());

        queue<string> q;

        q.push(beginWord);

        int ladder = 1;

        while (!q.empty())
        {
            int size = q.size();
            for (int jk = 0; jk < size; jk++)
            {
                string cur = q.front();
                q.pop();
                visited.insert(cur);
                if (cur == endWord)
                    return ladder;

                for (int i = 0; i < cur.size(); i++)
                {
                    char temp = cur[i];

                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        cur[i] = j;

                        if (dict.find(cur) != dict.end() && visited.find(cur) == visited.end())
                        {
                            visited.insert(cur);
                            q.push(cur);
                        }
                    }

                    cur[i] = temp;
                }
            }
            ladder++;
        }

        return 0;
    }
};