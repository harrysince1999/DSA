class Solution {
public:
    bool check(string& s,int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int i,vector<int>& dp)
    {
        if(i==s.size()) return 0;
        if(dp[i]!=-1)   return dp[i];
        
        int minCut = INT_MAX;
        for(int j=i;j<s.size();j++)
        {
            if(check(s,i,j))
            {
                int cut = 1+solve(s,j+1,dp);
                minCut = min(minCut,cut);
            }
        }
        return dp[i]=minCut;
    }
    int minCut(string s) {
        vector<int>dp(20001,-1);
        return solve(s,0,dp)-1;
    }
};