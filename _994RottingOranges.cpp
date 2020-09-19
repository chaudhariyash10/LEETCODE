#include<stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>>& grid)
{
    int freshCount = 0;
    queue<vector<int>> q;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
                freshCount++;

            if (grid[i][j] == 2)
            {
                q.push({ i, j });
            }
        }
    }

    vector<vector<int>> direction{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    int time = 0;

    while (!q.empty() && freshCount > 0)
    {

        int size = q.size();
        time++;
        while (size-- > 0)
        {
          
            int xy[2];
            xy[0] = q.front()[0];
            xy[1] = q.front()[1];

            q.pop();

            for(int k = 0; k < direction.size(); k++)
            {
                
                int x = xy[0] + direction[k][0];
                int y = xy[1] + direction[k][1];

                if (x < 0 || y < 0 || x >= grid.size() ||
                    y >= grid[0].size() || grid[x][y] == 0 || grid[x][y] == 2)
                    continue;

                if (grid[x][y] == 1)
                {
                    freshCount--;
                    grid[x][y] = 2;
                    q.push({ x, y });
                }
            }
        }
    }


    if (freshCount == 0)
        return time;

    else
    {
        return -1;
    }


}

int main()
{
    vector<vector<int>> grid{ { 2, 1, 1 }, { 1, 1, 0 }, { 0, 1, 1 } };


    int res = rottingOranges(grid);

    cout<<res;
}