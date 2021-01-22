#include <iostream>
#include <vector>
#include <algorithm>

#define v(int) vector<int>
#define ll long long
#define for (x, n) for (int x = 0; x < n; i++)

using namespace std;

ll helper(int n, int cur, ll prev1, ll prev2)
{
    if (cur > n)
        return prev1;

    else
    {
        return helper(n , cur+ 1 , prev1 + prev2 , prev1);
    }
}

ll fib(int n)
{
    if (n == 0)
        return 0;

    else if (n == 1)
    {
        return 1;
    }

    else
    {
        return helper(n, 2, 1, 0);
    }
}

int main()
{   cout<<"Enter a Number: ";
    int n;
    cin >> n;

    ll res = fib(n);
    cout<<"\n"<<res;
}