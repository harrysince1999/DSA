class Solution {
public:
    int find(vector<int>& nums)
    {
        int l = 0;
        int h = nums.size()-1;
        int n = nums.size();
        while(l<=h)
        {
            int mid = (l+h)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
                return mid;
            else if(nums[mid]<=nums[n-1])
                h= mid-1;
            else if(nums[mid]>=nums[0])
                l = mid+1;
        }
        return 0;
    }
    int search(vector<int>& nums, int target) {
        int minIdx = find(nums);
        //cout<<minIdx<<" ";
        int n = nums.size();
        int i,j;
        if(target<=nums[n-1] && target>=nums[minIdx])
        {
            i=minIdx;
            j=n-1;
        }
        else
        {
            i=0;
            j=minIdx-1;
        }
        
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(nums[mid]==target)   return mid;
            else if(nums[mid]<target)
                i= mid+1;

            else
                j=mid-1;
        }
        return -1;
    }
};