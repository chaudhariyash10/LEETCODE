#include <stdc++.h>

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
TreeNode *insert(TreeNode *root, int val)
{

    if (root == nullptr)
    {
        TreeNode *temp = new TreeNode(val);
        root = temp;
    }

    else
    {
        if (root->val > val)
        {
            root->left = insert(root->left, val);
        }

        else
        {
            root->right = insert(root->right, val);
        }
    }
    return root;
}

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);
    while (q.size() > 0)
    {
        vector<int> v;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            v.push_back(temp->val);
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        ans.push_back(v);
    }

    int i = 0, j = ans.size() - 1;

    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
}