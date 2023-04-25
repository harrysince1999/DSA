class Solution {
public:
    bool check(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string& s, int i, string& str, vector<vector<string>> &ans)
    {
        if(i==s.size())
        {
            vector<string>o;
            int x = 0;
            while(x<str.size())
            {
                string temp="";
                while(x<str.size() && str[x]!='@')
                {
                    temp+= str[x];
                    x++;
                }
                x++;
                if(check(temp)==true)
                    o.push_back(temp);
                else
                    return;
            }
            ans.push_back(o);
            return;
        }
        
        if(i!=0)
        {
            str+='@';
            str+=s[i];
            solve(s,i+1,str,ans);
            str.pop_back();
            str.pop_back();
        }
        
        str+= s[i];
        solve(s,i+1,str,ans);
        str.pop_back();

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        string str="";
        solve(s,0,str,ans);
        return ans;
    }
};