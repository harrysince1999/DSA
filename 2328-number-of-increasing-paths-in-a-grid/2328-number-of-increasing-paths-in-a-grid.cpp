class Solution {
public:
    int mod = 1e9+7;
    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>>& dp){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int up=0, down=0, left =0, right=0;
        if(i-1>=0 && grid[i][j]<grid[i-1][j])
            up= solve(grid,i-1,j,dp);
        if(i+1<grid.size() && grid[i][j]<grid[i+1][j])        
            down = solve(grid,i+1,j,dp);
        if(j-1>=0 && grid[i][j]<grid[i][j-1])
            left = solve(grid,i,j-1,dp);
        if(j+1<grid[0].size() && grid[i][j]<grid[i][j+1])
            right = solve(grid,i,j+1,dp);
        
        return dp[i][j]=(1+up+down+left+right)%mod;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans = (ans + solve(grid,i,j,dp))%mod;
            }
        }
        return ans%mod;
    }
};
