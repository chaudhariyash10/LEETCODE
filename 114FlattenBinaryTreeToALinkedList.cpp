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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        stack<TreeNode *> st;

        st.push(root);

        while (!st.empty())
        {
            TreeNode *curNode = st.top();
            st.pop();

            if (curNode->right)
                st.push(curNode->right);
            if (curNode->left)
                st.push(curNode->left);

            if (!st.empty())
            {
                curNode->right = st.top();
            }
            else
            {
                curNode->right = nullptr;
            }
            curNode->left = nullptr;
        }
    }
};