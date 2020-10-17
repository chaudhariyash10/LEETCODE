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

int minDepthHelper(TreeNode *root, int soFar)
{
   if(root->left == nullptr && root-> right == nullptr)
       return soFar + 1;

   else{
       int k = INT_MAX, l = INT_MAX;
       if(root->left)
           k = minDepthHelper(root->left, soFar+ 1);

       if(root->right)
           l = minDepthHelper(root->right, soFar+1);

       return min(k,l);
   }    
}
int minDepth(TreeNode *root)
{
    if(root == nullptr)
        return 0;

    return minDepthHelper(root, 0);
}

int main()
{
}