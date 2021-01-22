#include <bits/stdc++.h>

using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    stack<TreeNode *> st;

    st.push(root);
    int level = 0;

    while (!st.empty())
    {
        stack<TreeNode *> tempStack;
        vector<int> v;
        int size = st.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = st.top();

            v.push_back(temp->val);
            st.pop();

            if (level % 2 == 1)
            {
                if (temp->right)
                    tempStack.push(temp->right);
                if (temp->left)
                    tempStack.push(temp->left);
            }
            else
            {
                if (temp->left)
                    tempStack.push(temp->left);
                if (temp->right)
                    tempStack.push(temp->right);
            }
        }

        st = tempStack;
        level++;
        ans.push_back(v);
    }
    return ans;
}