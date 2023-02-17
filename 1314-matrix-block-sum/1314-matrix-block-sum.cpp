class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m =mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            int sum =0;
            for(int j=0;j<m;j++)
            {
                sum+= mat[i][j];
                dp[i][j]=sum;
            }
        }
        
        vector<vector<int>> ans(n,vector<int> (m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int rstart = max(i-k,0);
                int rend = min(i+k,n-1);
                int colstart = max(j-k,0);
                int colend = min(j+k,m-1);

                int a = colstart-1;
                int sum =0;
                if(a<0)
                {
                    for(int r=rstart;r<=rend;r++)
                        sum+= dp[r][colend];
                }
                else
                {
                    for(int r=rstart;r<=rend;r++)
                        sum+= (dp[r][colend]-dp[r][a]);
                }
                ans[i][j]=sum;
            }
        }
        return ans; 
    }
};