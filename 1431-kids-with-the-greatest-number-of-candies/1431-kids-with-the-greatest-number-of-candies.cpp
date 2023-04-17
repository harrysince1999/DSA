class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int mx = candies[0];
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]>mx)
                mx = candies[i];
            candies[i]+= extraCandies;
        }
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]>=mx)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};