class Solution {
public:
    bool isPrime(int n)
    {
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)  return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(isPrime(nums[i][i]) && nums[i][i]>ans)
                ans=nums[i][i];
        }
        for(int i=0;i<nums.size();i++)
        {
            int j = nums.size()-i-1;
            if(isPrime(nums[i][j]) && nums[i][j]>ans)
                ans=nums[i][j];
        }
        return ans;
    }
};