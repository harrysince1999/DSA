//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

bool search(int target, int i, int j,int arr[])
{
    while(i<=j)
    {
        int mid = (j-i)/2+i;
        if(arr[mid]==target)
            return true;
        if(arr[mid]<target)
            i=mid+1;
        else
            j=mid-1;
    }
    return false;
}
bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    // 2 3 5 5 20 80
    for(int i=0;i<size-1;i++)
    {
        bool find = search(n+arr[i],i+1,size-1,arr);
        if(find)
            return true;
    }
    return false;
}