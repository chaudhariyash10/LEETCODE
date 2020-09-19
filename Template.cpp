#include<stdc++.h>


using namespace std;

int main()
{
    vector<vector<int>> ans;

    for (int i = 0; i < 3; i++)
        ans[i].resize(3);

    ans[2][1] = 7;

    cout << ans[2][1];
}