class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)    return (double)1;
        if(x==0)    return (double)0;
        
        double res = myPow(x,n/2);
        if(n%2==0)
            return res*res;
        else
        {
            if(n>0) return res*res*x;
            else
                return res*res*(1/x);
        }
    }
};