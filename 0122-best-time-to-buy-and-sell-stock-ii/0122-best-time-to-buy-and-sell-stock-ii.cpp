class Solution {
public:
    int solve(vector<int>& prices,int i,int buy, vector<vector<int>>& dp)
    {
        if(i==prices.size())    return 0;
        if(dp[i][buy]!=-1)  return dp[i][buy];
        if(buy==0) 
        {
            // Buy Karna Hai
            int b1= -prices[i]+solve(prices,i+1,1,dp);
            // buy Nhi karna Hai
            int b2= solve(prices,i+1,0,dp);
            return dp[i][buy]=max(b1,b2);
        }
        
        else
        {
            // sell karna hai
            int s1 = prices[i]+solve(prices,i+1,0,dp);
            // sell nhi karna hai
            int s2 = solve(prices,i+1,1,dp);
            return dp[i][buy]=max(s1,s2);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};