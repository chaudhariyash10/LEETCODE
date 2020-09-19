#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int helper(int n , int cur , int prev1, int prev2)
{
    if(n < cur)
    return prev1;

    else{
        return helper(n , cur+1 , prev1 + prev2 , prev1);
    }
}
//Note : Its Like Fibinacci sequence;
int climbStairs(int n)
{
    if(n == 0)
    return 0;

    else if(n == 1)
    return 1;

    else if(n == 2)
    return 2;

    else
    {
        return helper(n , 3 , 2, 1);
    }
}

int main()
{
    int n;
    cout<<"Enter Number Of Stairs: ";
    cin>>n;

    int noOfWays = climbStairs(n);

    cout<<noOfWays;
}