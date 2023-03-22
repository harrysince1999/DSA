//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int count=0;
        int zero=0, one=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0') zero++;
            if(str[i]=='1') one++;
            
            if(zero==one){
                zero=0;
                one=0;
                count++;
            }
        }
        if(zero!=0 || one!=0)   return -1;
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends