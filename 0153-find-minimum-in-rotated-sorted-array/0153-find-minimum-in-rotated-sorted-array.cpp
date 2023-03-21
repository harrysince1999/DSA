class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(nums[mid]>nums[h])
                l=mid+1;
            else
                h=mid;
        }
        return nums[l];
    }
};