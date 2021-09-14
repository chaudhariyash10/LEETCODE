#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> nearestSmallerToLeft(vector<int> hgt)
    {
        vector<int> res;
        if (hgt.size() == 0)
            return res;
        stack<int> st;

        for (int i = 0; i < hgt.size(); i++)
        {
            if (st.empty())
            {
                res.push_back(-1);
            }
            else if (hgt[st.top()] >= hgt[i])
            {
                while (!st.empty() && hgt[st.top()] > hgt[i])
                {
                    st.pop();
                }

                if (st.empty())
                {
                    res.push_back(-1);
                }
                else
                {
                    res.push_back(st.top());
                }
            }
            else
            {
                res.push_back(st.top());
            }
            st.push(i);
        }

        return res;
    }
    vector<int> nearestSmallerToRight(vector<int> hgt)
    {
        vector<int> res(hgt.size());
        if (hgt.size() == 0)
            return res;
        stack<int> st;

        for (int i = hgt.size() - 1; i >= 0; i--)
        {
            if (st.empty())
                res[i] = (hgt.size());

            else if (hgt[st.top()] >= hgt[i])
            {
                while (!st.empty() && hgt[st.top()] >= hgt[i])
                    st.pop();

                if (st.empty())
                    res[i] = (hgt.size());
                else
                    res[i] = st.top();
            }
            else
                res[i] = st.top();
            st.push(i);
        }

        return res;
    }
    int MAH(vector<int> hgt)
    {
        vector<int> left = nearestSmallerToLeft(hgt);
        vector<int> right = nearestSmallerToRight(hgt);

        int maxArea = 0;

        for (int i = 0; i < hgt.size(); i++)
        {
            if (maxArea < (right[i] - left[i] - 1) * hgt[i])
                maxArea = (right[i] - left[i] - 1) * hgt[i];
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &mat)
    {
        if (mat.size() == 0)
            return 0;

        vector<int> prev(mat[0].size()), cur(mat[0].size());

        int maxArea = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == '0')
                    cur[j] = 0;
                else
                    cur[j] = mat[i][j] - 48 + prev[j];
            }

            maxArea = max(maxArea, MAH(cur));

            prev = cur;
        }

        return maxArea;
    }
};