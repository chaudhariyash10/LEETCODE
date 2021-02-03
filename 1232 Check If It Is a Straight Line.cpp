#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(vector<int> &v1, vector<int> &v2)
    {
        return (v1[0] > v2[0]);
    }

    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        bool flag = true;

        sort(coordinates.begin(), coordinates.end(), compare);

        float slope = (coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]);
        float tempSlope;
        for (int i = 1; i < coordinates.size() - 1; i++)
        {
            tempSlope = (coordinates[i][1] - coordinates[i + 1][1]) / (coordinates[i][0] - coordinates[i + 1][0]);
            if (tempSlope != slope)
            {
                flag = false;
                break;
            }
        }

        return flag;
    }
};