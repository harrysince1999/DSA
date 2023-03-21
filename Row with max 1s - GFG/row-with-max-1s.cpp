//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int row = -1;
        int ans = INT_MIN;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            int l=0;
            int h=m-1;
            
            while(l<=h)
            {
                int mid= (l+h)/2;
                
                if(arr[i][mid]==1)
                    h=mid-1;
                else
                    l=mid+1;
            }
            
            int no= (m-l);
            if(no>0)
                flag = true;
            if(no > ans)
            {
                ans = no;
                row = i;
            }
            
        }
        if(flag == false)    return -1;
        return row;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends