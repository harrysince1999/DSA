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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int is, int ie,
                   int ps, int pe, map<int,int>& mp)
    {
        if(is>ie || ps>pe)  return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int idx = mp[root->val];
        int rem = idx-is;
        
        root->left = solve(inorder,postorder,is,idx-1,ps,ps+rem-1,mp);
        root->right = solve(inorder,postorder,idx+1,ie,ps+rem,pe-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode* root = solve(inorder,postorder, 0, inorder.size()-1, 
                               0, postorder.size()-1, mp);
        return root;
    }
};