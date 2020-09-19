#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string reverseWords(string s)
{
    string temp , ans;
    stringstream iss(s);
    bool first = true;
    while (iss >> temp){
        if(first){
         first = false;
         ans = temp;
        }

        else
        {
            ans = temp + " " + ans;
        }
        

    } 

    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    string result = reverseWords(s);
   
  cout << result;
}
