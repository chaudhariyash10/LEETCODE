#include <stdc++.h>

using namespace std;

//Time:O(n)
//Space: O(n)

// void moveZeroes(vector<int> &nums)
// {
//     vector<int> ans;

//     int zero = 0;
//     //Count Number of zeroes
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == 0)
//             zero++;
//     }
//     //Retain Order of Non zeroes
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i])
//             ans.push_back(nums[i]);
//     }

//     //Copy and Add Zeroes

//     for (int i = 0; i < ans.size(); i++)
//     {
//         nums[i] = ans[i];
//     }
//     int j = ans.size();
//     while (j < nums.size())
//     {
//         nums[j] = 0;
//         j++;
//     }
// }

//Time: O(n)
//Space: O(1)

// void moveZeroes(vector<int> &nums)
// {
//     int lastNonZero = 0;
//     //Getting all Non-Zero At front
//     for (int i = 0; i < nums.size(); i++) {
//         if(nums[i]){
//             nums[lastNonZero++] = nums[i];
//         }
//     }

//     //Appending Zeroes
//     for (int i = lastNonZero; i < nums.size(); i++){
//         nums[i] = 0;
//     }
// }


//Most optimal
void moveZeroes(vector<int> &nums)
{
    for (int lastNonZero = 0, cur = 0; cur < nums.size(); cur++){
        if(nums[cur]){
            int temp = nums[lastNonZero];
            nums[lastNonZero++] = nums[cur];
            nums[cur] = temp;
        }
    }
}
int main()
{
    vector<int> v{1,0,2,0,2,0};

    moveZeroes(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}