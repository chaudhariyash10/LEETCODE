#include <stdc++.h>

using namespace std;

char nextGreatestLetter(vector<char> &v, char target)
{
    int left = 0, right = v.size(), mid;

    while(left < right)
    {
        mid = left + (right - left) / 2;

        if(v[mid] <= target)
            left = mid + 1;
       else
       {
           right = mid;
       }
        }

        return v[left % (v.size())];
}

int main()
{
    vector<char> v{'c', 'f', 'j'};
    char target ='g';

    cout << nextGreatestLetter(v, target);
}