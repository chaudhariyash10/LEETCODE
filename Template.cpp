#include<stdc++.h>


using namespace std;

int main()
{
    char x = '8';
    string s;
    s.push_back(x);

    s += "seen at" + to_string(1) + " " + to_string(2);

    cout << s;
}