#include<stdc++.h>


using namespace std;

int search(vector<int> v, int target) {

    if (v.size() < 1)
        return -1;

    int left = 0, right = v.size() - 1;

    while (left  < right) {

        int mid = left + (right - left) / 2;

        if (v[right] < v[mid]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }


    int start = left;

    left = 0; right = v.size() -1;

    if (target >= v[start] && target <= v[right]) {
        left = start;
    }
    else
    {
        right = start;
    }



    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == v[mid])
            return mid;

        else if(target < v[mid]){ 
            right = mid - 1;
        }
        else{ 
            left = mid+1;
        }
    }


    return -1;
}

int main() {
    vector<int> v ={ 4, 5, 6, 7, 0, 1, 2 };

    int target = 0;

    cout << search(v, target);
}