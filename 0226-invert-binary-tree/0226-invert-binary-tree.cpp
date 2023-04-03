/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* &l, TreeNode* &r)
    {
        if(l==NULL && r==NULL)   return;
        swap(l,r);
        if(l!=NULL)
            solve(l->left,l->right);
        if(r!=NULL)
            solve(r->left,r->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)  return root;
        solve(root->left,root->right);
        return root;
    }
};