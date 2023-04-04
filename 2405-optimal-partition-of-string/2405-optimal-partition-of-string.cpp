class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        set<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.find(s[i])==st.end())     // present nhi hai
            {
                st.insert(s[i]);
            }
            else                // present hai
            {
                ans++;
                st.clear();
                st.insert(s[i]);
            }
        }
        if(!st.empty()) ans++;
        return ans;
    }
};