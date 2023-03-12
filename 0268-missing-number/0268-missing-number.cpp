class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0;
        for(auto it: nums)
            s+= it;
        int n = nums.size();
        int ts = (n*(n+1))/2;
        return ts-s;
    }
};