//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string S){
    //complete the function here
    string ans = "";
    for(int i=0;i<S.size();i++)
    {
        S[i]= (char)tolower(S[i]);
    }
    char prev = S[0];
    int count = 0;
    for(int i=0;i<S.size();i++)
    {
        if(S[i]==prev)
            count++;
        else
        {
            ans+= to_string(count);
            ans+= prev;
            prev = S[i];
            count = 1;
        }
    }
    ans+= to_string(count);
    ans+= prev;
    return ans;
}

