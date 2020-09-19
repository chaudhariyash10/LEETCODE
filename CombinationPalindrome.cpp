#include <stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    unordered_map<char, int> umap;

    for (int i = 0; i < s.size(); i++)
    {   
        
        if (isalnum(s[i]))
        {
            char ch = tolower(s[i]);
            if (!umap[ch])
            {
                umap[ch] = 1;
            }
            else
            {
                umap[ch]++;
            }
        }
    }

    int odd = false;

    for (auto &x : umap)
    {
        if (x.second % 2 != 0)
        {
            if (odd == false)
                odd = true;
            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << s;
    cout << isPalindrome(s);
}