class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int ans = INT_MIN;
        if(s.size()==0)      return 0;
        int l = 0;
        for(int r=0;r<s.size();r++){
            if(st.find(s[r])!=st.end())
            {
                while(l<r && st.find(s[r]) != st.end())
                {
                    st.erase(s[l]);
                    l++;
                }
            }
            ans = max(ans, r-l+1);
           st.insert(s[r]);
        }
        return ans;
    }
};