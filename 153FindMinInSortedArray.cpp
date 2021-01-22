#include<stdc++.h>


using namespace std;

int findMin(vector<int> v){

    if (v.size() < 1)
        return -1;

    int left = 0, right = v.size() - 1;

    while(left < right){ 
        int mid = left + (right - left) / 2;

        if(v[right] < v[mid]){ 
            left = mid + 1;
        }
        else { 
            right = mid;
        }
    }

    return v[left];
}

int main()
{
    vector<int> v{ 5, 6, 7, 0, 1, 2, 4 };

    cout<<findMin(v);
}