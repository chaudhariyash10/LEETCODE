#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &v)
{
    int j = 1, i = 0;

    if (v.size() < 2)
        return v.size();

    while (i < v.size() && j < v.size())
    {
        if (v[j - 1] == v[j])
        {
            j++;
        }

        else
        {
            v[i + 1] = v[j];
            i++;
            j++;
        }
    }

    return i + 1;
}
int main()
{
    vector<int> v;

    v = {1, 2, 2};

    int newlenght = removeDuplicates(v);

    cout << newlenght;

    for (int i = 0; i < newlenght; i++)
    {
        cout << "\t" << v[i];
    }
}