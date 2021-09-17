#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    stack<long long> st;
    long long mini;
    /** initialize your data structure here. */
    MinStack()
    {
        mini = -1;
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }

        else if (val >= mini)
        {
            st.push(val);
        }
        else
        {
            st.push(2 * (long long)val - mini);
            mini = val;
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        else
        {
            if (st.top() < mini)
            {
                mini = mini * 2 - st.top();
            }
            st.pop();
        }
    }

    int top()
    {
        if (st.top() < mini)
            return mini;
        else
            return st.top();
    }

    int getMin()
    {
        return mini;
    }
};