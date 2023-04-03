//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int count(int n)
    {
        int ans = 0;
        while(n)
        {
            if(n%2==1)  ans++;
            n = n/2;
        }
        return ans;
    }
    static bool cmp(pair<int,int>v1,pair<int,int>v2)
    {
        int x=(v1.first);
        int y=(v2.first);
        if(x==y)
        {
            return v1.second<v2.second;
        }
        return v1.first>v2.first;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({count(arr[i]),i});
        
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(auto x:v) ans.push_back(arr[x.second]);
        for(int i=0;i<n;i++) arr[i]=ans[i];
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends