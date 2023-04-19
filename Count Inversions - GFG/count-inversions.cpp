//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans = 0;
    void mergeSort(long long arr[], long long low, long long mid, long long high)
    {
        long long n1 = mid-low+1;
        long long n2 = high-mid;
        
        long long arr1[n1];
        long long arr2[n2];
        
        for(int i=0;i<n1;i++)
            arr1[i]=arr[i+low];
        
        for(int i=0;i<n2;i++)
            arr2[i]=arr[i+mid+1];
            
        long long i=0;
        long long j=0;
        long x =low;
        while(i<n1 && j<n2)
        {
            if(arr1[i]<=arr2[j])
            {
                arr[x++]=arr1[i++];
            }
            else
            {
                ans += (n1-i);
                arr[x++]=arr2[j++];
            }
        }
        
        while(i<n1)
        {
            arr[x++]=arr1[i++];
        }
        
        while(j<n2)
        {
            arr[x++]=arr2[j++];
        }
        
        return;
    }
    void merge(long long arr[],long long low, long long high)
    {
        if(low<high)
        {
            long long mid = (high-low)/2+low;
            merge(arr,low,mid);
            merge(arr,mid+1,high);
            mergeSort(arr,low,mid,high);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        merge(arr,0,N-1);
        return ans;        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends