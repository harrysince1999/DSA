//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(vector<int>& stalls, int n, int k, int mid)
    {
        int count = 1;
        int prev = 0;
        for(int i=1;i<stalls.size();i++)
        {
            int diff = stalls[i]-stalls[prev];
            if(diff>=mid)
            {
                count++;
                prev = i;
            }
        }
        return count>=k;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int i = 1;
        int j = stalls[n-1]-stalls[0];
        int ans = -1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(isPossible(stalls,n,k,mid))
            {
                ans = mid;
                i= mid+1;
            }
            else
                j=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends