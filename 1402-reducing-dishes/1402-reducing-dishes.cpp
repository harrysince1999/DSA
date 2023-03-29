class Solution {
public:
    int solve(vector<int>& s, int i,int call,vector<vector<int>>&dp){
        if(i>=s.size())
            return 0;
        if(dp[i][call]!=-1) return dp[i][call];
        
        int a= s[i]*call + solve(s,i+1,call+1,dp);
        int b = solve(s,i+1,call,dp);
        return dp[i][call]=max(a,b);
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));
        return solve(s,0,1,dp);
    }
};

