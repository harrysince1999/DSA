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
    void solve(TreeNode* a)
    {
        if(a==NULL)  return;
        swap(a->left,a->right);
        
        solve(a->left);
        solve(a->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};