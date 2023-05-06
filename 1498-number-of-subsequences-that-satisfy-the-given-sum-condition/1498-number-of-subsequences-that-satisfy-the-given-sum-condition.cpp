class Solution {
public:
    const int M =1e9+7;
    int binexp(int a, int b)
    {
        if(b==0) return 1;
        
        int val = binexp(a,b/2);
        val = (val*1LL*val)%M;
        if(b%2) val = (val*1LL*a)%M;
        
        return val;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int j= nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            while(j>=i && nums[j]+nums[i]>target)
                j--;
            if(j>=i)
            {
                 int x = binexp(2,j-i);
                 ans = (ans+x)%M;
            }
               
        }
        return ans;
    }
};