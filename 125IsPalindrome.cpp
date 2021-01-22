#include <stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    int start = 0, last = s.size() - 1;


    while (start <= last)
    {
        if (start == last)
            return true;
        while (!isalnum(s[start]) && start < last)
        {
            start++;
            }

        while (!isalnum(s[last]) && start < last)
            {
                last--;
                
            }

                char sc = tolower(s[start]);
                char lc = tolower(s[last]);
                if (lc != sc)
                {
                    return false;
        }
        else
        {
            start++;
            last--;
        }
    }

    return true;
}

int main()
{
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << isPalindrome(s);
}