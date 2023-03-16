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
    TreeNode* solve(vector<int>& inorder,int is,int ie,
                   vector<int>& preorder,int ps, int pe, map<int,int>& mp)
    {
        if(is>ie || ps>pe)  return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int idx = mp[preorder[ps]];
        int rem = idx-is;
        
        root->left = solve(inorder,is,idx-1,preorder,ps+1,ps+rem,mp);
        root->right = solve(inorder,idx+1,ie,preorder,ps+rem+1,pe,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return solve(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);
    }
};
