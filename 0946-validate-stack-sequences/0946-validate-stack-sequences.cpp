class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; 
        int j = 0;
        for(auto it : pushed)
        {
            st.push(it);
            while(st.size() > 0 && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.size() == 0;
    }
};