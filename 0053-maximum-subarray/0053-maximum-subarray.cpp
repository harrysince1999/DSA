class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int mx = INT_MIN;
        for(int i =0;i<nums.size();i++)
        {
            curr+= nums[i];
            mx = max(curr,mx);
            if(curr<0)  curr=0;
        }
        return mx;
    }
};