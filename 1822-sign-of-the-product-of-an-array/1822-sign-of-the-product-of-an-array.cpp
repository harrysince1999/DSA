class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount =0;
        int posCount =0;
        for(auto it: nums){
            if(it<0)    negCount++;
            else if(it>0)   posCount++;
            else
                return 0;
        }
        if(negCount%2==0)  return 1;
        return -1;
    }
};