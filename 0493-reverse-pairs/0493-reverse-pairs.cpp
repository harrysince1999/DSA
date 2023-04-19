class Solution {
public:
    int ans = 0;
    void merge(vector<int> &nums, int l, int mid, int h){
        int n1 = mid-l+1;
        int n2 = h-mid;
        
        vector<int>a(n1,0);
        vector<int>b(n2,0);
        
        for(int i=0;i<n1;i++)
            a[i]=nums[i+l];
        for(int i=0;i<n2;i++)
            b[i]=nums[mid+1+i];
        
        int i=0,j=0,x=l;
        while(i<n1 && j<n2)
        {
            long long x = (1ll*2*b[j]);
            if(a[i]>x)
            {
                ans += (n1-i);
                j++;
            }
            else
                i++;
        }
        
        i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(a[i]<=b[j])
            {
                nums[x++]=a[i++];
            }
            else
                nums[x++]=b[j++];
        }
        while(i<n1)
            nums[x++]=a[i++];
        while(j<n2)
            nums[x++]=b[j++];
    }
    void mergeSort(vector<int>& nums, int l, int h)
    {
        if(l<h)
        {
            int mid = (h+l)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,h);
            merge(nums,l,mid,h);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};