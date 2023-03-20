//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int>l(n,arr[n-1]);
        vector<int>r(n,arr[0]);
        for(int i=n-2;i>=0;i--)
            l[i]=max(arr[i],l[i+1]);
    
        for(int i=1;i<n;i++)
            r[i]=max(arr[i],r[i-1]);
        
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans+= min(l[i],r[i])-arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends