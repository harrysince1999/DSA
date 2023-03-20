class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        if(n==0)    return true;
        if(fb.size()==1)    return fb[0]==0;
        
        fb.insert(fb.begin(),0);
        fb.push_back(0);
        int i=0;
        int c=0;
        while(i<fb.size()-2)
        {
            if(fb[i]==0 && fb[i+1]==0 && fb[i+2]==0)
            {
                c++;
                fb[i+1]=1;
            }
            i++;
        }
        cout<<c<<" ";
        if(c>=n)    return true;
        return false;
    }
};