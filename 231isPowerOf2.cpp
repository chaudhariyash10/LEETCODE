#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    if (n < 0)
        return false;

    if ((n & (n - 1)) == 0)
        return true;
    else
        return false;
}

int main()
{

    cout << "Enter a number:" << endl;

    int n;
    cin >> n;

    cout << isPowerOfTwo(n);
}