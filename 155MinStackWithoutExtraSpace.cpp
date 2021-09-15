#include <bits/stdc++.h>
using namespace std;

class MinStack
{

public:
    stack<int> s;
    stack<int> minStack;
    void push(int val)
    {
        if (minStack.empty() || minStack.top() >= val)
            minStack.push(val);
        s.push(val);
    }

    void pop()
    {
        if (s.empty())
            return;
        if (s.top() == minStack.top())
            minStack.pop();
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};