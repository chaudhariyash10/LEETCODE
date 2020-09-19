#include<stdc++.h>

using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, bool> umap;

    for (int i = 0; i < nums.size(); i++){
        if(umap[nums[i]]){
            return true;
        }

        umap[nums[i]] = true;
    }

    return false;
}

int main() {
    vector<int> nums{1, 2, 3, 4};

    cout << containsDuplicate(nums);
}