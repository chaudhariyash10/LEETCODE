#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Using Time: O(n) ans spcae O(n) IN-place reverse;

void helper(vector<char> &s, int left, int right)
{

    if (left >= right)
        return;

    char temp = s[right];
    s[right] = s[left];
    s[left] = temp;

    right--;
    left++;

    helper(s, left, right);
}
void recursion(vector<char> &s)
{
    helper(s, 0, s.size() - 1);
}

//Time: O(n) And space : O (1)
void iteration(vector<char> &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }
}

int main()
{

    vector<char> s = {'s', 'a', 'k', 's', 'h', 'i'};
    iteration(s);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s.at(i);
    }
}