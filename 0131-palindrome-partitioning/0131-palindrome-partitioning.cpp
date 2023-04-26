class Solution {
public:
    bool check(string s,int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string& s, int i, vector<string>& result, vector<vector<string>>& ans){
        if(i==s.size())
        {
            ans.push_back(result);
            return;
        }
        
        for(int j=i;j<s.size();j++)
        {
            if(check(s,i,j))
            {
                result.push_back(s.substr(i,j-i+1));
                solve(s,j+1,result,ans);
                result.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>result;
        solve(s,0,result,ans);
        return ans;
    }
};