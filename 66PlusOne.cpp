#include <stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int size = digits.size() - 1;
    int carry = 1;

    while(size >= 0 && carry == 1){
        if(digits[size] == 9){
            digits[size] = 0;
            
        }

        else{
            digits[size]++;
            carry = 0;
        }

        size--;
    }

    if(carry == 1){
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main()
{
    vector<int> v{9, 9, 9};
    v = plusOne(v);

    for (int i = 0; i < v.size(); i++){
        cout << v[i];
    }
}