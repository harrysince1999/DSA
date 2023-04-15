class Solution {
public:
int sumi(int ind, vector<vector<int>> &piles, int k, int n, vector<vector<int>> &dp){
    if(ind==n or k==0) return 0;
    if(dp[ind][k]!=-1) return dp[ind][k];
    int notPick=sumi(ind+1,piles,k,n,dp);
    int pick=0,coins=k,sum=0;
    for(int i=0;i<piles[ind].size() and coins>0;i++){
        sum+=piles[ind][i];
        coins--;
        int x=sum+sumi(ind+1,piles,coins,n,dp);
        pick=max(pick,x);
    }
    return dp[ind][k]=max(pick,notPick);
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        int ind=0;
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        return sumi(ind,piles,k,n,dp);
    }
};