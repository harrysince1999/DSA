//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int A[], int N, int M, int mid)
    {
        int pageSum = 0;
        int stud = 1;
        for(int i=0;i<N;i++)
        {
            if(pageSum+A[i] <= mid)
            {
                pageSum+= A[i];
            }
            else
            {
                stud++;
                if(stud>M || A[i]>mid) 
                    return false;
                pageSum = A[i];
            }
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        int ans = -1;
        if(N<M) return ans;
        int sum = 0;
        for(int i=0;i<N;i++)
            sum+= A[i];
        int s = 0;
        int e = sum;
        while(s<=e)
        {
            int mid = (e-s)/2+s;
            if(isPossible(A,N,M,mid))
            {
                ans = mid;
                e=mid-1;
            }
                
            else
                s= mid+1;
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