class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                int a=i;
                int b=i;
                while(b<nums.size() && nums[b]==0)
                    b++;
                long long count = b-a;
                if(count%2==0)
                    ans+= (count/2)*(count+1);
                else
                    ans+= (count)*((count+1)/2);
                i=b;
            }
        }
        return ans;
    }
};