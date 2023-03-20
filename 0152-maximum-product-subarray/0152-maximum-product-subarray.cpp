class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int p=1;
        for(auto it: nums)
        {
            p=p*it;
            ans = max(ans,p);
            if(p==0)
                p=1;
        }
        p=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            p=p*nums[i];
            ans = max(ans,p);
            if(p==0)
                p=1;
        }
        return ans;
    }
};