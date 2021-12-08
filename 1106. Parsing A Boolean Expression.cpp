#include <bits/stdc++.h>
using namespace std;

//|(&(t,f,t),!(t))
class Solution
{
public:
    bool parseBoolExpr(string exp)
    {
        stack<char> st;

        int i = 0;
        while (i < exp.size())
        {
            if (exp[i] == ')')
            {
                bool hasTrue = false, hasFalse = false;

                char cur;

                while (st.top() != '(')
                {
                    st.top();
                    if (st.top() == 't')
                        hasTrue = true;
                    else if (st.top() == 'f')
                        hasFalse = true;
                    st.pop();
                }

                st.pop();

                char op = st.top();
                st.pop();

                if (op == '&' && hasTrue && !hasFalse)
                    st.push('t');
                else if ((op == '|') && hasTrue)
                    st.push('t');
                else if (op == '!' && hasFalse)
                    st.push('t');
                else
                    st.push('f');
            }
            else
                st.push(exp[i]);

            i++;
        }

        return st.top() == 't' ? true : false;
    }
};