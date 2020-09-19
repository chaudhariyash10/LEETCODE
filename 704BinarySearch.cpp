#include<stdc++.h>

using namespace std;

int helper(vector<int> v, int beg, int end , int target)
{   
    if(beg > end){
        return -1;
    }
    int mid = (beg + end) / 2;

    if(target == v[mid])
        return mid;

     else if(target < v[mid])
        {
            return helper(v, beg, mid-1 , target);
        }

      else{
          return helper(v, mid+1, end, target);
      }  
}

int search(vector<int> v, int target)
{
    return helper(v, 0, v.size()-1, target);
}

int main()
{
    vector<int> v{-1, 0, 3, 5, 9, 12};

    int pos = search(v , 2);

    cout << pos;


}