class Solution {
public:
    void solve(vector<int>& c, int i, vector<int>& o, int t, vector<vector<int>>& ans)
    {
        if(i==c.size())
        {
            if(t==0)
                ans.push_back(o);
            return;
        }
        
        solve(c,i+1,o,t,ans);
        
        if(c[i]<=t)
        {
            o.push_back(c[i]);
            solve(c,i,o,t-c[i],ans);
            o.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> o;
        solve(c,0,o,t,ans);
        return ans;
    }
};