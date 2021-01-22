#include <stdc++.h>

using namespace std;
//Using Two Hash Maps


vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, bool> umap;
    unordered_map<int, bool> done;


    for (int i = 0; i < nums1.size(); i++){
        if(!umap[nums1[i]]){
            umap[nums1[i]] = true;
        }
    }

    vector<int> ans;

    for (int i = 0; i < nums2.size(); i++){
        if(umap[nums2[i]] && !done[nums2[i]]){
            ans.push_back(nums2[i]);
            done[nums2[i]] = true;
        }
    }

    return ans;
}

//Using Sorting And Two pointer....

// vector<int> intersection(vector<int> &nums1, vector<int> &nums2){
//     vector<int> ans;

//     sort(nums1.begin(), nums1.end());
//     sort(nums2.begin(), nums2.end());

//     int l = 0, r = 0;

//     while(  l  < nums1.size() - 1&& r < nums2.size() - 1){
//         while (nums1[l] == nums1[l + 1] && l < nums1.size() - 1){
//             l++;
//         }
//         while (nums2[r] == nums2[r + 1] && r < nums2.size() - 1){
//             r++;
//         }

//             if (nums1[l] < nums2[r])
//             {
//                 l++;
//             }

//             else if (nums1[l] > nums2[r])
//             {
//                 r++;
//             }

//             else{
//             ans.push_back(nums1[l]);
//             l++;
//             r++;
//         }
//     }

//     return ans;
// }

    int main()
{
    vector<int> nums1{1,2,2,4};
    vector<int> nums2{2,2,4,5};

    vector<int> v= intersection(nums1, nums2);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\t";

        
}