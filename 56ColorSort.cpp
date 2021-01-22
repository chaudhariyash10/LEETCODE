#include <stdc++.h>

using namespace std;

void merge(vector<int> &nums, int l, int mid, int r)
{
    if(l >= r)
        return;

    vector<int> c, b;

    for (int i = l; i <= mid; i++)
        b.push_back(nums[i]);

    for (int i = mid + 1; i <= r; i++)
        c.push_back(nums[i]);

    int i = 0, j = 0, k = l;

    while( i < b.size() && j < c.size())
    {
        if(b[i] <= c[j])
        {
            nums[k++] = b[i++];
        }
        else{
            nums[k++] = c[j++];
        }
    }

    while(i < b.size())
        nums[k++] = b[i++];

    while(j < c.size())
        nums[k++] = c[j++];
}

void mergeSort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;

    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);

    merge(nums, l, mid, r);
}

void colorSort(vector<int> &nums)
{   
    if(nums.size() < 2)
        return;

    mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {2, 0, 1, 2, 2, 1, 0};
}