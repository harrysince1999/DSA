class Solution {
public:
    int solve(string a, string b, int i, int j,vector<vector<int>>& dp)
    {
        if(i<0)    return j+1;
        if(j<0)     return i+1;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(a[i]==b[j])  return dp[i][j]=solve(a,b,i-1,j-1,dp);
        
        else
        {
            int x = 1+solve(a,b,i-1,j,dp);
            int y = 1+solve(a,b,i,j-1,dp);
            int z = 1+solve(a,b,i-1,j-1,dp);
            return dp[i][j]=min(x,min(y,z));
        }
    }
    int minDistance(string a, string b) {
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
        return solve(a,b,a.size(),b.size(),dp);
    }
};