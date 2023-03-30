bool dp[33][33][33];
int visited[33][33][33];
int cas;
string a,b;
int n;
//checking if both string has similar letter count
bool check(vector<int>&a, vector<int>&b){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
bool recur(int l1,int l2, int len){
    if(len==1){
        return (l1>=0 && l1<n && l2>=0 && l2<n && a[l1] == b[l2]);
    }

    int &visi = visited[l1][l2][len];
    bool &ans = dp[l1][l2][len];
    if(visi == cas)return ans;
    ans = false;
    visi = cas;

    int r1 = l1+len-1;
    int r2 = l2+len-1;
    vector<int>cnta = vector<int>(27,0);
    vector<int>cntb = vector<int>(27,0);

    for(int i=l1,j=l2;i<=r1;i++,j++){
        cnta[a[i]-'a']++;
        cntb[b[j]-'a']++;
    }
    if(check(cnta, cntb)==false){
        //string part aren't same by char
        return false;

    }
    int lena = 0;
    int lenb = len;
    for(int i=l1,j=l2;i<=r1;i++,j++){
        lena++;
        lenb--;
        //no swap
        ans = recur(l1,l2,lena) && recur(l1+lena, l2+lena, lenb);
        if(ans)return ans;
        //swap
        ans = recur(l1,l2+len-lena,lena) && recur(l1+lena, l2, lenb);
        if(ans)return ans;
        
    }
    return ans;
}
class Solution {
public:

    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())return false;
        cas++;
        n = s1.size();
        a = s1;
        b = s2;
        return recur(0,0,n);
    }
};