class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            int mid = (r-l)/2+l;
            if(mid%2!=0 && nums[mid]==nums[mid-1] || (mid%2==0 && nums[mid]==nums[mid+1]))
                l=mid+1;
            else
                r=mid;
        }
        return nums[l];
    }
};