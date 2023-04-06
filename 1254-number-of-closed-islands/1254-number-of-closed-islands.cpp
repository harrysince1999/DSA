class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int i, int j, int r, int c)
    {
        if(i<r && j<c && i>=0 && j>=0 && grid[i][j]==0)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid,int i, int j, int r, int c)
    {
        grid[i][j]=1;
        int ax[4] = {1,-1,0,0};
        int ay[4] = {0,0,1,-1};
        
        for(int k=0;k<4;k++)
        {
            int nx = i+ ax[k];
            int ny = j+ ay[k];
            
            if(isValid(grid,nx,ny,r,c))
                dfs(grid,nx,ny,r,c);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i*j==0 || i==r-1 || j==c-1){
                    if(grid[i][j]==0)
                        dfs(grid,i,j,r,c);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(grid,i,j,r,c);
                }
            }
        }
        return ans;
    }
};