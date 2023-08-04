//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[], int val[],int i, int n,vector<vector<int>>& dp)
    {
        if(i==n)
            return 0;
        
        if(dp[W][i]!=-1)    return dp[W][i];
        
        int notTake = 0;
        int take =0;
        
        if(wt[i]<=W)
        {
            take = val[i]+solve(W-wt[i],wt,val,i+1,n,dp);
        }
        
        notTake = solve(W,wt,val,i+1,n,dp);
        
        return dp[W][i]=max(take,notTake);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
        return solve(W,wt,val,0,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends