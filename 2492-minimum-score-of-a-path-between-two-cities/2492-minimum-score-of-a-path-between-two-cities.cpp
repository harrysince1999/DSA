class Solution {
public:
    
    void dfs(vector<pair<int,int>> a[],int node,vector<int> &path,vector<int> &vis)
    {
        vis[node]=1;
        path.push_back(node);
        for(auto x:a[node])
        {
            if(!vis[x.first])
                dfs(a,x.first,path,vis);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> a[n+1];
        for(auto x:roads)
        {
            a[x[0]].push_back({x[1],x[2]});
            a[x[1]].push_back({x[0],x[2]});
        }
       
        vector<int> path;
        vector<int> vis(n+1,0);
        int ans=INT_MAX;
        dfs(a,1,path,vis);
        for(auto x:path)
        {
            for(auto y:a[x])
                ans=min(ans,y.second);
        }
        return ans;
    }
};