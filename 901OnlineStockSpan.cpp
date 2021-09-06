#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
    stack<pair<int, int>> st;
    int count;

public:
    StockSpanner()
    {
        count = 0;
    }

    int next(int price)
    {
        count++;
        if (st.empty())
        {
            st.push({price, count});
            return 1;
        }
        else if (st.top().first > price)
        {
            st.push({price, count});
            return 1;
        }
        else
        {
            while (!st.empty() && st.top().first <= price)
                st.pop();

            if (st.empty())
            {
                st.push({price, count});
                return count;
            }
            else
            {
                int temp = st.top().second;
                st.push({price, count});
                return count - temp;
            }
        }
        return 0;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */