#include <iostream>

using namespace std;

string addBinary(string a, string b)
{
    string res = "";

    int alen = a.length() - 1, blen = b.length() - 1, k = 0;

    bool carry = 0;


    while(k <= alen || k <= blen){
        int val = (k <= alen && a[alen - k] == '1') + (k <= blen && b[blen - k] == '1') + carry;

        res = to_string(val % 2) + res;

        carry = val>= 2;
        k++;
    }

    if(carry ){
        res = to_string(carry) + res;
    }

    return res;
}

int main()
{
    string a, b;

    cin >> a >> b;

    string res = addBinary(a, b);
    cout<<res;
}