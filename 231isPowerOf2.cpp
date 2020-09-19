#include <iostream>

using namespace std;

bool isPower(int n)
{
    bool res =true;

    if(n == 1){
        return true;
    }

    while(n > 1){
        if( n  % 2 != 0){
            return false;
        }

        n = n / 2;

    }

    return res;
}

int main()
{

    cout << "Enter a number:" << endl;

    int n;
    cin >> n;

    cout<<isPower(n);
}