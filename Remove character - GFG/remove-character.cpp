//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
#include<bits/stdc++.h>
class Solution {
  public:
    string removeChars(string string1, string string2) {
        map<char,int> mp;
        for(auto it: string2)
            mp[it]++;
        string ans ="";
        for(auto it: string1)
        {
            if(mp.find(it)==mp.end())
                ans+=it;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

// } Driver Code Ends