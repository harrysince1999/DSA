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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)  return {};
        bool flag = true;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp!=NULL)
            {
                v.push_back(temp->val);
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
                
            }
            else
            {
                if(q.size()>0)
                    q.push(NULL);
                if(flag == false){
                    reverse(v.begin(),v.end());
                    ans.push_back(v);
                }
                else
                    ans.push_back(v);
                v.clear();
                flag = !flag;
            }
        }
        return ans;
    }
};