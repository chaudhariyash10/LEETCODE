#include <stdc++.h>

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
class Solution
{
public:
    void convertArray(TreeNode *root, vector<int> &nums, int l, int r)
    {
        if (l == r)
            return;

        int mid = l + (r - l) / 2;
        root->val = nums[mid];

        if (l != mid)
        {
            root->left = new TreeNode();
            convertArray(root->left, nums, l, mid);
        }
        if (mid + 1 != r)
        {
            root->right = new TreeNode();
            convertArray(root->right, nums, mid + 1, r);
        }
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if(nums.size() < 1)
            return nullptr;
        TreeNode *root = new TreeNode();
        convertArray(root, nums, 0, nums.size());

        return root;
    }
};
int main()
{
}