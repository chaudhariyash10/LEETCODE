#include <stdc++.h>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    unordered_map<int , int> umap;
    
    for(int i = 0; i< nums1.size(); i++){
        if( !umap[nums1[i]]){
            umap[nums1[i]] = 1;
        }
        else{
            umap[nums1[i]]++;
        }
    }

    for(int i = 0; i < nums2.size(); i++){
        if(umap[nums2[i]]){
            ans.push_back(nums2[i]);
            umap[nums2[i]]--;
        }

    }

    return ans;
}
int main()
{
    vector<int> nums1{1, 2, 2, 4};
    vector<int> nums2{2, 2, 4, 5};

    vector<int> v = intersect(nums1, nums2);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\t";
}
