class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int>ans(t.size(),1);
        stack<pair<int,int>>st;
        for(int i=t.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans[i]=0;
                st.push({t[i],i});
            }
            else
            {
                while(!st.empty() && st.top().first<=t[i])
                    st.pop();
                if(st.empty())
                {
                    ans[i]=0;
                    st.push({t[i],i});
                }
                else
                {
                    ans[i]= st.top().second-i;
                    st.push({t[i],i});
                }
            }
        }
        return ans;
    }
};