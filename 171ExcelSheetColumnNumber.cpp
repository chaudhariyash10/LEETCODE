#include<stdc++.h>


using namespace std;

int titleToNumber(string s)
{
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        

        ans = ans*26 + (s[i] - 64);

    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

   cout<<titleToNumber(s);
}