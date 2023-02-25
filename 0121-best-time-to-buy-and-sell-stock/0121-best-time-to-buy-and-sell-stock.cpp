class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<int> ivec(p.size(),-1);
        for(int i=0;i<p.size();i++)
            ivec[i] = -p[i];
        
        vector<int> maxvec(p.size(),p[p.size()-1]);
        
        for(int i=p.size()-2;i>=0;i--)
            maxvec[i]= max(maxvec[i+1],p[i]);
        
        int ans = INT_MIN;
        for(int i=0;i<p.size()-1;i++)
        {
            int temp = ivec[i]+maxvec[i+1];
            ans = max(ans,temp);
        }
        if(ans<0)   return 0;
        return ans;
    }
};