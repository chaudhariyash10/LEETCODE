//using binary search

#include <stdc++.h>

using namespace std;

long long mySqrt(long long x)
{
    long long ans = 0;
    long long left = 0, right = x;
    long long mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (mid * mid == x)
            return mid;

        else if (mid * mid < x)
        {
            ans = mid;
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{
    long long x;
    cout << "Enter x: ";
    cin >> x;

    cout << sqrt(x);
}