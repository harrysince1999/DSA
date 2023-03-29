class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0, j= n-1;
        while(i<=j)
        {
            int mid = (j-i)/2+i;
            if(nums[mid]==target)   return mid;
            else if(nums[mid]>=nums[i]) // left side strictly increasing hai
            {
                if(target<=nums[mid] && target>=nums[i])
                    j= mid-1;
                else
                    i=mid+1;
            }
            else
            {
                if(target<=nums[j] && target>=nums[mid])
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        return -1;
    }
};