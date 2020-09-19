#include<stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& a) {

    vector<vector<int>> result;


    if (a.size()<3)
        return result;


    sort(a.begin(), a.end());


    for (int i=0;i<a.size()-2;i++)
    {
        int start=i+1;
        int end=a.size()-1;

       
        if (i>0 and a[i]==a[i-1])
            continue;

        while (start<end)
        {
            if (a[start]+a[end]==-a[i])
            {
                result.push_back({ a[start], a[i], a[end] });
                start++;
                end--;


                while (start<end and a[start]==a[start-1])
                    start++;
                while (start<end and a[end]==a[end+1])
                    end--;
            }
            else if (a[start]+a[end]>-a[i])
                end--;
            else
                start++;
        }

    }

    return result;
}

int main()
{
    vector<int> v{ -2, 0, 0, 2, 2 };



    vector<vector<int>> res = threeSum(v);


    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }

        cout<<endl;
    }
}