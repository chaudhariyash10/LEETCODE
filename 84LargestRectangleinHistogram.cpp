#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> nearestSmallerToLeft(vector<int> &heights)
    {
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < heights.size(); i++)
        {
            if (st.empty())
            {
                ans.emplace_back(-1);
            }
            else if (heights[st.top()] < heights[i])
            {
                ans.emplace_back(st.top());
            }
            else
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();

                if (st.empty())
                    ans.emplace_back(-1);
                else
                    ans.emplace_back(st.top());
            }
            st.push(i);
        }

        return ans;
    }
    vector<int> nearestSmallerToRight(vector<int> &heights)
    {
        vector<int> ans(heights.size());
        stack<int> st;

        for (int i = heights.size() - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                ans[i] = heights.size();
            }
            else if (heights[st.top()] < heights[i])
            {
                ans.emplace_back(st.top());
                ans[i] = st.top();
            }
            else
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();

                if (st.empty())
                    ans[i] = heights.size();
                else
                    ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.size() == 0)
            return 0;

        if (heights.size() == 1)
            return heights[0];

        // vector<int> heights{6, 2, 5, 4, 5, 1, 6};
        vector<int> left = nearestSmallerToLeft(heights);
        vector<int> right = nearestSmallerToRight(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            if (maxArea < (right[i] - left[i] - 1) * heights[i])
                maxArea = (right[i] - left[i] - 1) * heights[i];
        }

        return maxArea;
    }
};