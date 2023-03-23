//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    int count = 0;
    int n = s.size();
    if(n%2!=0)   return -1;
    
    stack<char> st;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{')
            st.push(s[i]);
        else
        {
            if(st.empty())
            {
                count++;
                st.push('{');
            }
            else
            {
                st.pop();
            }
        }
    }
    int rem = st.size();
    count+= rem/2;
    if(rem%2!=0)
        count++;
    return count;
}