class Solution {
public:
    int solve(vector<int>& piles, int val){
        int x = 0;
        for(auto it: piles)
            x+= (it+val-1)/val;
        return x;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1, hi=1e9;
        while(lo<hi)
        {
            int mid= (hi+lo)/2;
            if(solve(piles,mid)>h)
                lo=mid+1;
            else
                hi=mid;
        }
        return lo;
    }
};