#include <stdc++.h>

using namespace std;

double myPow(double x, long n)
{
    if (n == 0)
        return 1;
    if (n > 0)
        return myPow(x, n);
    else
        return 1 / myPow(x, -n);
}
double Pow(double x, long n)
{
    if (n == 0)
        return 1;

    else if (n % 2 == 0)
        return Pow(x * x, n / 2);

    else
        return x *
               Pow(x * x, (n - 1) / 2);
}

int main()
{
    float x;
    int n;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter n: ";
    cin >> n;

    cout << Pow(x, n) << endl;
}