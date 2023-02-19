class Solution {
public:
    int solve(int i,int a, vector<int>& coins,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(a%coins[0]==0)   return 1;
            return 0;
        }
        if(dp[i][a]!=-1)    return dp[i][a];
        int notTake = solve(i-1,a,coins,dp);
        int take = 0;
        if(coins[i]<=a)
            take = solve(i,a-coins[i],coins,dp);
        
        return dp[i][a]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp);
    }
};
