class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        vector<int> ans;
        int n = p.size();
        sort(p.begin(),p.end());
        
        for(int i=0;i<s.size();i++)
        {
            int count=0;
            long long prod = s[i]*1ll*p[n-1];
            if(prod>=success)
            {
                int l = 0;
                int r = n-1;
                while(l<=r)
                {
                    int mid = (r-l)/2+l;
                    long long temp = p[mid]*1ll*s[i];
                    if(temp >= success)
                        r=mid-1;
                    else
                    {
                        l = mid+1;
                    }
                }
                ans.push_back(n-l);
            }
            else 
                ans.push_back(0);
        }
        return ans;
    }
};