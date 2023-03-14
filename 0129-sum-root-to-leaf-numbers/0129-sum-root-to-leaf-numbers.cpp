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
    int solve(TreeNode* root, int curr, int sum){
        if(root==NULL)  return 0;
        curr = curr*10+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum+= curr;
            return sum;
        }
            
        return solve(root->left,curr,sum)+solve(root->right,curr, sum);
    }
    int sumNumbers(TreeNode* root) {
        int curr=0, sum = 0;
        return solve(root,curr,sum);
    }
};