class Solution {
public:
    string longestPalindrome(string s) {
        string str ="";
        str+= s[0];
        int ans =1 ;
        for(int i=1;i<s.size();i++)
        {
            int l=i-1;
            int h=i;
            while(l>=0 && h<s.size() && s[l]==s[h])
            {
                if(h-l+1 > ans)
                {
                    ans = h-l+1;
                    str = s.substr(l,h-l+1);
                }
                l--;
                h++;
            }
        }
        for(int i=1;i<s.size();i++)
        {
            int l=i-1;
            int h=i+1;
            while(l>=0 && h<s.size() && s[l]==s[h])
            {
                if(h-l+1 > ans)
                {
                    ans = h-l+1;
                    str = s.substr(l,h-l+1);
                }
                l--;
                h++;
            }
        }
        return str;
    }
};