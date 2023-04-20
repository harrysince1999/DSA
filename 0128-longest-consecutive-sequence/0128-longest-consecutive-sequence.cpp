class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        
        set<int>st;
        for(auto it: nums)
            st.insert(it);
        
        vector<int> a;
        for(auto it: st)
            a.push_back(it);
        
        int ans = 0;
        int curr = 1;
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i]+1==a[i+1])
                curr++;
            else
            {
                ans = max(ans,curr);
                curr=1;
            }
        }
        ans = max(ans,curr);
        return ans;
    }
};