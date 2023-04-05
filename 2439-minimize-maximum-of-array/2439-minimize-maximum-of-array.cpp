class Solution {
public:
    bool isPossible(vector<long long> nums, long long mid)
    {
        if(nums[0]>mid) return false;
        for(int i=1;i<nums.size();i++)
        {
            long long diff= mid-nums[i-1];
            nums[i-1] += diff;
            nums[i]-= diff;
            if(nums[i]>mid) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& arr) {
        vector<long long>nums;
        for(auto it:arr)
            nums.push_back(it);

        int s=0, e=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>e)
                e=nums[i];
        }
        
        int ans = 0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(nums,mid))
            {
                ans = mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};