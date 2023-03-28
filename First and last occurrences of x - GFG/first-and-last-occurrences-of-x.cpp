//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    int start = 0, end = n-1;
    int first = -1, second =-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==x)
        {
            first = mid;
            end = mid-1;
        }
        else if(arr[mid]>x)
        {
            end = mid-1;
        }
        else
            start = mid+1;
    }
    ans.push_back(first);
    start = 0, end = n-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==x)
        {
            second = mid;
            start = mid+1;
        }
        else if(arr[mid]>x)
        {
            end = mid-1;
        }
        else
            start = mid+1;
    }
    ans.push_back(second);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends