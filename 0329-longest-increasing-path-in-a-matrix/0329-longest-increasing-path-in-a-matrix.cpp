class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i, int j, vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
            return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int u=0, d=0, l=0, r=0;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
            u = solve(matrix,i-1,j,dp);
        
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j])
            d = solve(matrix,i+1,j,dp);
        
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
            l = solve(matrix,i,j-1,dp);
        
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j])
            r = solve(matrix,i,j+1,dp);
        
        return dp[i][j]= 1+max(u,max(d,max(l,r)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c,-1));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans = max(ans,solve(matrix,i,j,dp));
            }
        }
        return ans;
    }
};