//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int count=0;
        for(int i=0;i<n;i++)
            if(arr[i]<=k)   count++;
        
        int ans = INT_MAX;
        int tc = 0;
        for(int i=0;i<count;i++)
        {
            if(arr[i]>k)
                tc++;
        }
        ans = tc;
        int i=0;
        int j=count-1;
        while(j<n-1)
        {
            j++;
            if(arr[j]>k)
                tc++;
            if(arr[i]>k)
                tc--;
            i++;
           // cout<<tc<<" ";
            ans= min(ans,tc);
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends