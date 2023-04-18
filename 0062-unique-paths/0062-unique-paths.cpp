class Solution {
public:
    int solve(int r, int c, int i, int j,vector<vector<int>>& dp){
        if(i==r-1 && j==c-1)    return 1;
        if(i>=r || j>= c)   return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int down = solve(r,c,i+1,j,dp);
        int right = solve(r,c,i,j+1,dp);
        
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,dp);
    }
};