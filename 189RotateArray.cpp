#include <stdc++.h>

using namespace std;

//time: O(n) space: O(n)

// void rotate(vector<int> &v, int k)
// {
//     if (v.size() <= 1)
//     {
//         return;
//     }
//     vector<int> v1(v);
//     int s = v.size();
//     k = k % s;

//     for (int i = 0; i < s; i++)
//     {
//         v1[(i + k) % s] = v[i];
//     }
//     v = v1;
// }

// 1)Reverse Whole array
// 2)Reverse first k elements
// 3)Reverse last n-k elements

//Time: O(n) space: O(1)

void reverse(vector<int> &v , int l , int h)
{
    int temp;
    while (l < h)
    {
        temp = v[l];
        v[l] = v[h];
        v[h] = temp;

        l++;
        h--;
    }
}
void rotate(vector<int> &v, int k)
{
    if(v.size() <= 1){
        return;
    }
    k = k % v.size();
    reverse(v, 0, v.size() - 1);                // 7 6 5 4 3 2 1
    reverse(v, 0, k - 1);                       // 5 6 7 4 3 2 1
    reverse(v, k, v.size() - 1);                // 5 6 7 1 2 3 4 --ans
}

int main()
{
    vector<int> v{1,2};
    
    int k = 3;

    rotate(v, k);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
}