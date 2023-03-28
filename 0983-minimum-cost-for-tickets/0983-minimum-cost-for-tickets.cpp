class Solution {
public:
    int solve(vector<int> &days , vector<int>& costs , int i , vector<int>& dp){
        if(i >= days.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int a  = costs[0] + solve(days,costs,i+1,dp);
        auto val = lower_bound(days.begin() , days.end() , days[i]+7)-days.begin();
        int b  = costs[1] + solve(days,costs,val,dp);
        auto val2 = lower_bound(days.begin() , days.end() , days[i]+30)-days.begin();
        int c  = costs[2] + solve(days,costs,val2,dp);
        
        return dp[i] = min(a,min(b,c));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366 , -1);
        return solve(days,costs,0,dp);
    }
};