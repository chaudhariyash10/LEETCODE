#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        if (s.size() == 0)
            return s;
        unordered_map<char, int> umap;
        vector<bool> present(26);

        for (int i = 0; i < s.size(); i++)
            umap[s[i]]++;

        stack<char> st;

        st.push(s[0]);
        umap[s[0]]--;
        present[s[0] - 97] = true;
        for (int i = 1; i < s.size(); i++)
        {
            if (present[s[i] - 97])
                ;
            else if (st.top() < s[i])
                st.push(s[i]);
            else
            {
                while (!st.empty() && umap[st.top()] > 0 && st.top() > s[i])
                {
                    present[st.top() - 97] = false;
                    st.pop();
                }
                st.push(s[i]);
            }
            present[s[i] - 97] = true;
            umap[s[i]]--;
        }

        string ans = "";

        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};