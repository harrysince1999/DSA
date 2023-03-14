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
    int ans = 0;
    void solve(TreeNode* root,vector<int>&v)
    {
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(root->val);
            int x =0;
            for(auto it: v)
            {
                x = x*10+it;
            }
            ans+=x;
            v.pop_back();
            return;
        }
        
        if(root->left!=NULL)
        {
            v.push_back(root->val);
            solve(root->left,v);
            v.pop_back();
        }
        
        if(root->right!=NULL)
        {
            v.push_back(root->val);
            solve(root->right,v);
            v.pop_back();
        }

    }
    int sumNumbers(TreeNode* root) {
        vector<int>v;
        solve(root,v);
        return ans;
    }
};