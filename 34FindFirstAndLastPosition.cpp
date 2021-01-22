#include<stdc++.h>

using namespace std;

vector<int> searchRange(vector<int> v, int target) {
    int left = 0, right = v.size() - 1;

    while (left < right) {
        int mid = left + (right -left) / 2;

        if (target  v[mid]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    cout<<left;
    return { -1 , -1 };
}

int main()
{
    vector<int> v{ 5, 7, 7, 8, 8, 10 };
    int target = 8;

    vector<int> ans = searchRange(v, target);

    for (auto x : ans)
        cout<<x;
}