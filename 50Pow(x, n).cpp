#include <stdc++.h>

using namespace std;
double Pow(double x, long n)
{
    if (n == 0)
        return 1;

    else if (n % 2 == 0)
        return myPow(x * x, n / 2);

    else
        return x * myPow(x * x, (n - 1) / 2);
}

double myPow(double x, long n)
{
    if (n == 0)
        return 1;
    if (n > 0)
        return Pow(x, n);
    else
        return 1 / Pow(x, -n);
}

int main()
{
    float x;
    int n;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter n: ";
    cin >> n;

    cout << Pow(x, n);
}