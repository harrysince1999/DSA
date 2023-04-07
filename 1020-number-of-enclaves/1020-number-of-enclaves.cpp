class Solution {
public:
    bool isPossible(vector<vector<int>>& grid, int i, int j, int r, int c)
    {
        if(i<r && i>=0 && j<c && j>=0 && grid[i][j]==1)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c)
    {
        grid[i][j]=0;
        
        if(isPossible(grid,i+1,j,r,c))
            dfs(grid,i+1,j,r,c);
        if(isPossible(grid,i,j+1,r,c))
            dfs(grid,i,j+1,r,c);
        if(isPossible(grid,i-1,j,r,c))
            dfs(grid,i-1,j,r,c);
        if(isPossible(grid,i,j-1,r,c))
            dfs(grid,i,j-1,r,c);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i*j==0 || i==r-1 || j==c-1){
                    if(grid[i][j]==1)
                        dfs(grid,i,j,r,c);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};