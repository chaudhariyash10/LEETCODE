#include<stdc++.h>
using namespace std;

int main()
{
    char n;
    L0:
    cin >> n;

    if(n < '0' || n > '9')
    {
        cout << "Invalid Input";
        goto L0;
    }

    int k = (int)n - 48;

    cout << k;
}