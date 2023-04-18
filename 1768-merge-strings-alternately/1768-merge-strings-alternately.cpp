class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        bool flag = false;
        string ans ="";
        while(i<word1.size() && j<word2.size())
        {
            if(flag==false)
                ans.push_back(word1[i++]);
            else
                ans.push_back(word2[j++]);
            flag=!flag;
        }
        while(i<word1.size())
            ans.push_back(word1[i++]);
        while(j<word2.size())
            ans.push_back(word2[j++]);
        return ans;
    }
};