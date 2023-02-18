class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j,vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
            return grid[i][j];
        
        if(i<0 || j<0)  return 1e9;
        if(dp[i][j]!=-1)    return dp[i][j];
        int a = grid[i][j] + solve(grid,i-1,j,dp);
        int b= grid[i][j] + solve(grid,i,j-1,dp);
        
        return dp[i][j]=min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c,-1));
        return solve(grid,r-1,c-1,dp);
    }
};