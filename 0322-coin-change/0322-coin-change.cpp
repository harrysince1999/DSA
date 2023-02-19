class Solution {
public:
    int solve(vector<int>& coins, int a, int i,vector<vector<int>>& dp){
        
        if(i==coins.size())  
        {
            if(a==0)
                return 1;
            return 1e9;
        }
        if(dp[a][i]!=-1)    return dp[a][i];
        
        int notTake = solve(coins,a,i+1,dp);
        int take = 1e9;
        if(coins[i]<=a)
            take = 1+solve(coins,a-coins[i],i,dp);
        
        return dp[a][i]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int a) {
        vector<vector<int>> dp(a+1,vector<int>(coins.size(),-1));
        int x= solve(coins,a,0,dp);
        if(x==1e9)  return -1;
        return x-1;
    }
};