class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int ans = 0;
        vector<int> l(n,h[0]);
        vector<int> r(n,h[n-1]);
        
        for(int i=1;i<n;i++)
            l[i]=max(l[i-1],h[i]);
        for(int i=n-2;i>=0;i--)
            r[i]=max(r[i+1],h[i]);
        
        for(int i=0;i<h.size();i++)
        {
            int a = l[i];
            int b = r[i];
            ans += min(a,b)-h[i];
        }
        return ans;
    }
};