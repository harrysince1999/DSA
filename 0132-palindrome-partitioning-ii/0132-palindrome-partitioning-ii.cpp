class Solution {
public:
    bool isTrue(int i, int j, string& s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string s, int i,vector<int>& dp)
    {
        if(i==s.size()) return 0;
        if(dp[i]!=-1)   return dp[i];
        int minCost = INT_MAX;
        for(int j=i;j<s.size();j++)
        {
            if(isTrue(i,j,s))
            {
                int cost = 1+solve(s,j+1,dp);
                minCost = min(minCost,cost);
            }
        }
        return dp[i]=minCost;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return solve(s,0,dp)-1;
    }
};