#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//Space: 5%
//Runtime: 43%

class Solution
{
public:
    vector<vector<int>> ans;
    void Util(TreeNode *root, int sum, int runningSum, vector<int> soFar)
    {
        if(root == nullptr)
            return;

        runningSum += root->val;
        soFar.push_back(root->val);
        if (root->right == nullptr &&root->left == nullptr && runningSum == sum)
            ans.push_back(soFar);

        else{
            if(root-> right)
                Util(root->right, sum, runningSum, soFar);
            if(root->left)
                Util(root->left, sum, runningSum, soFar);
        }    
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        
        if (root == nullptr)
            return ans;
        vector<int> soFar;
        Util(root, sum, 0, soFar);
        return ans;
    }
};


//Better Runtime....
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    void Util(TreeNode *root, int sum)
    {
        path.push_back(root->val);

        if (root->right == nullptr && root->left == nullptr && root->val == sum)
            ans.push_back(path);

        else
        {
            if (root->right)
                Util(root->right, sum);
            if (root->left)
                Util(root->left, sum);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {

        if (root == nullptr)
            return ans;
        
        Util(root, sum);
        return ans;
    }
};

int main()
{

}