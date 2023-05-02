//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int arr[], int n, int m, int mid)
    {
        int pagesCount = 0;
        int book = 1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)  return false;
            else if(arr[i]+pagesCount>mid)
            {
                pagesCount= arr[i];
                book++;
            }
            else
            {
                pagesCount+= arr[i];
            }
        }
        if(book>m)
            return false;
        return true;
    }
    int findPages(int arr[], int n, int m) 
    {
        int low = arr[0];
        int high = 0;
        int ans = -1;
        if(n<m) return ans;
        for(int i=0;i<n;i++){
            low = min(low,arr[i]);
            high += arr[i];
        }

        while(low<=high)
        {
            int mid = (high-low)/2+low;
            if(isPossible(arr,n,m,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
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