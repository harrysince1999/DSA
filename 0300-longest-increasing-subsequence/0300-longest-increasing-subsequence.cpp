class Solution {
public:
    int solve(vector<int>& nums, int prev, int i,vector<vector<int>>& dp)
    {
        if(i==nums.size())  return 0;
        if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        
        int take =0;
        int notTake =0;
        
        notTake = solve(nums,prev,i+1,dp);
        if(prev==-1 || nums[prev]<nums[i])
            take = 1+solve(nums,i,i+1,dp);
        
        return dp[prev+1][i]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,-1,0,dp);
    }
};