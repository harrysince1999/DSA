class Solution {
public:
    string getPermutation(int n, int k) {
        int x = 1;
        vector<char> s;
        while(x<=n)
        {
            s.push_back(x+'0');
            x++;
        }
        while(k>1){
            next_permutation(s.begin(),s.end());
            k--;
        }
        string ans = "";
        for(int i=0;i<s.size();i++)
            ans+= s[i];
        return ans;
    }
};