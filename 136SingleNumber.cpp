#include <stdc++.h>

using namespace std;

//Time: O(n)  space: O(n)

// int singleNumber(vector<int> &nums)
// {
//     if(nums.size() == 1){
//         return nums[0];
//     }
//     unordered_map<int, bool> umap;

//     for (int i = 0; i < nums.size(); i++){
//         if(umap[nums[i]]){
//             umap[nums[i]] = false;
//         }
//         else{
//             umap[nums[i]] = true;
//         }
//     }

//     for(auto i: umap){
//         if(i.second){
//             return i.first;
//         }
//     }

//     return -1;
// }

//===================================================================================================================
//                  Logic
//       2(a+b+c) - (a+a+b+b+c) = c
//         Time: O(n) Space:O(n)
// int singleNumber(vector<int> &nums)
// {
//     int singleSum = 0;
//     int totalSum = 0;
//     unordered_map<int, bool> umap;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         totalSum += nums[i];
//         if(!umap[nums[i]]){
//             umap[nums[i]] = true;
//             singleSum += nums[i];
//         }
//     }
    
//     return 2 * singleSum-totalSum;
// }

//======================================================================================

/*If we take XOR of zero and some bit, it will return that bit
a ⊕ 0 = aa⊕0=a
If we take XOR of two same bits, it will return 0
a ⊕ a = 0a⊕a=0
a ⊕ b ⊕ a = (a ⊕ a) ⊕ b = 0 ⊕ b = ba⊕b⊕a=(a⊕a)⊕b=0⊕b=b*/

int singleNumber(vector<int> &nums){
    int ans = 0;

    for (int i = 0; i < nums.size(); i++){
        ans = ans ^ nums[i];
    }

    return ans;
}

    int main()
{
    vector<int> v{4, 2, 2, 1, 1, 3, 3};

    cout << singleNumber(v);

    
}