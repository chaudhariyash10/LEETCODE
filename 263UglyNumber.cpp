#include <iostream>

using namespace std;
//Time Limit Exceeds
bool isUgly(int n)
{
    if (n < 1)
        return false;
    bool ugly = true;
    int i = 2;
    while (n > 1)
    {
        if (n % i == 0)
        {
            if (i != 2 && i != 3 && i != 5)
            {
                ugly = false;
                break;
            }
            n = n / i;
        }
        else
            i++;
    }

    return ugly;
}

//Solution Accepted

bool isUglyAgain(int num)
{

    if (num <= 0)
    {
        return false;
    }
    while (num % 2 == 0)
    {
        num /= 2;
    }
    while (num % 3 == 0)
    {
        num /= 3;
    }
    while (num % 5 == 0)
    {
        num /= 5;
    }
    if (num == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    bool ugly = isUglyAgain(n);
    if (ugly)
        cout << "true" << endl;
    else
    {
        cout << "false" << endl;
    }
}