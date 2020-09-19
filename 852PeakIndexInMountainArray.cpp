#include<stdc++.h>

using namespace std;

int peakIndexInMountainArray(vector<int> v) {
    int left = 0, right = v.size() - 1, mid;

    while(left < right) {
        mid = left + (right - left) / 2;

        if(v[mid] > v[mid + 1])
            right = mid;
        else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    vector<int> v{0, 2, 0};



    cout << peakIndexInMountainArray(v);
}