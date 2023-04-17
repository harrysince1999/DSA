class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>temp(prices.size(),prices[prices.size()-1]);
        
        for(int i=prices.size()-2;i>=0;i--)
            temp[i]=max(temp[i+1],prices[i]);

        int ans=0;
        for(int i=0;i<prices.size()-1;i++)
            ans= max(ans,temp[i+1]-prices[i]);

        return ans;
    }
};