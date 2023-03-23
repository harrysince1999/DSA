//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

bool searchPattern(string str, string pat)
{
    for(int i=0;i<=str.size()-pat.size();i++)
    {
        int a = i;
        int b = 0;
        while(b<pat.size())
        {
            if(str[a]==pat[b])
            {
                a++;
                b++;
            }
            else
                break;
        }
        if(b==pat.size())   return true;
    }
    return false;
}



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}


// } Driver Code Ends