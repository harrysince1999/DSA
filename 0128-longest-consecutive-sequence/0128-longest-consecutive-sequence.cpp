class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        if(n==1)    return 1;
        
        sort(nums.begin(),nums.end());
        int curr=1;
        int maxi=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]+1==nums[i+1])
                curr++;
            else if(nums[i]!=nums[i+1])
            {
                maxi = max(maxi,curr);
                curr=1;
            }
        }
        return max(maxi,curr);
    }
};