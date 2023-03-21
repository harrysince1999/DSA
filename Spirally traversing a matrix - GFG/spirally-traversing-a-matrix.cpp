//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int row, int col) 
    {
        vector<int> ans;
        int c = row*col;
        int rs=0, re=row-1, cs =0, ce = col-1;
        bool r=true;
        bool d=false;
        bool l=false;
        bool u=false;
        while(c)
        {
            if(r==true)
            {
                for(int j=cs;j<=ce;j++)
                {
                    ans.push_back(m[rs][j]);
                    c--;
                }
                rs++;
                r=false;
                d=true;
            }
            else if(d==true)
            {
                for(int i= rs;i<=re;i++)
                {
                    ans.push_back(m[i][ce]);
                    c--;
                }
                ce--;
                d=false;
                l=true;
            }
            else if(l==true)
            {
                for(int i=ce;i>=cs;i--)
                {
                    ans.push_back(m[re][i]);
                    c--;
                }
                re--;
                l=false;
                u=true;
            }
            else if(u==true)
            {
                for(int i=re;i>=rs;i--)
                {
                    ans.push_back(m[i][cs]);
                    c--;
                }
                cs++;
                u=false;
                r=true;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends