#include<stdc++.h>

using namespace std;
bool isMonotonic(vector<int> v)
{
    bool increasing = true;
    bool decreasing = true;

    for(int i = 1; i < v.size(); i++)
    { 
        if (v[i] > v[i-1]) decreasing = false;
        if (v[i] < v[i-1]) increasing = false;

    }

    return increasing||decreasing;
}

int main()
{
    vector<int> v{1,1,1 };

    bool is = isMonotonic(v);

    cout<<is;
}