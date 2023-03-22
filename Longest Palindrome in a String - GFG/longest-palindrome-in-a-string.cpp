//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        char ch= S[0];
        string st="";
        st+=ch;
        int ans = 1;
        int l=0;
        int h=0;
        for(int i=1;i<S.size();i++)
        {
            l=i-1;
            h=i;
            while(l>=0 && h<S.size() && S[l]==S[h])
            {
                if(h-l+1>ans)
                {
                    ans= h-l+1;
                    st= S.substr(l,h-l+1);
                }
                l--;
                h++;
            }
        }
        for(int i=1;i<S.size();i++)
        {
            l=i-1;
            h=i+1;
            while(l>=0 && h<S.size() && S[l]==S[h])
            {
                if(h-l+1>ans)
                {
                    ans= h-l+1;
                    st= S.substr(l,h-l+1);
                }
                l--;
                h++;
            }
        }
        return st;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends