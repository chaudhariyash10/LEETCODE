#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();

        int hn = n - 1, hm = m - 1, ln = 0, lm = 0;

        while (ln <= hn && lm <= hm)
        {
            int midn = ln + (hn - ln) / 2;
            int midm = lm + (hm - lm) / 2;

            if (midn > 0 && mat[midn][midm] < mat[midn - 1][midm])
            {
                hn = midn - 1;
            }
            else if (midm < m - 1 && mat[midn][midm] < mat[midn][midm + 1])
            {
                lm = midm + 1;
            }
            else if (midn < n - 1 && mat[midn][midm] < mat[midn + 1][midm])
            {
                ln = midn + 1;
            }
            else if (midm > 0 && mat[midn][midm] < mat[midn][midm - 1])
            {
                hm = midm - 1;
            }
            else
                return vector<int>{midn, midm};
        }

        return vector<int>{-1, -1};
    }
};
