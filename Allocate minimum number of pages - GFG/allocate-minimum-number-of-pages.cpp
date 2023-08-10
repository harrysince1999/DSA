//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[], int n, int m, int mid){
        int num = 1;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>mid)    return false;
            else if(A[i]+sum <= mid)
            {
                sum+= A[i];
            }
            else
            {
                num++;
                sum= A[i];
            }
        }
        if(num>m)   return false;
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int ans = -1;
        int lo = A[0];
        int hi = 0;
        if(M>N) return -1;
        for(int i=0;i<N;i++)
        {
            lo = min(lo,A[i]);
            hi += A[i];
        }
        while(lo<=hi)
        {
            int mid = (hi-lo)/2+lo;
            if(isPossible(A,N,M,mid))
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends