class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        set<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.find(s[i])!=st.end()) 
            {
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return ans;
    }
};