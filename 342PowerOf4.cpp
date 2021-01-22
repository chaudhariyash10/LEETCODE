#include <stdc++.h>

using namespace std;

bool isPowerOfFour(int n)
{
    if (n < 1)
        return false;

    while (n > 1)
    {
        if (n % 4 != 0)
            return false;

        n = n / 4;
    }

    return true;
}

int main()
{
    cout << "Enter A Number: ";
    int n;
    cin >> n;

    cout << isPowerOfFour(n);
}