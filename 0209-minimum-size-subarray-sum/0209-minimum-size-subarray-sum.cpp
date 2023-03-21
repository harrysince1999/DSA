class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sortest = INT_MAX;
        int l=0;
        int r=0;
        int sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            if(sum>=target)
            {
                while(sum>=target)
                {
                    sum-=nums[l];
                    l++;
                }
                sortest= min(sortest,r-l+2);
            }
            r++;
        }
        return sortest==INT_MAX?0:sortest;
    }
};