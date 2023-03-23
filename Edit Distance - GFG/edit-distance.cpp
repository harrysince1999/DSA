//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string a, int i, string b, int j,vector<vector<int>>&dp){
        
        if(i>a.size())  return b.size()-j+1;
        if(j>b.size())  return a.size()-i+1;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=solve(a,i+1,b,j+1,dp);
        
        int x = 1+solve(a,i+1,b,j,dp);
        int y = 1+solve(a,i+1,b,j+1,dp);
        int z = 1+solve(a,i,b,j+1,dp);
        
        return dp[i][j]=min(x,min(y,z));
    }
    int editDistance(string a, string b) {
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,-1));
        return solve(a,0,b,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends