class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board)
    {
        int r=row;
        int c= col;
        while(c>=0)
        {
            if(board[r][c]=='Q')    return false;
            c--;
        }
        
        c=col;
        while(r>=0 && c>=0)
        {
            if(board[r][c]=='Q')    return false;
            r--;
            c--;
        }
        
        r=row;
        c=col;
        while(r<board.size() && c>=0)
        {
            if(board[r][c]=='Q')    return false;
            c--;
            r++;
        }
        return true;
    }
    void solve(vector<string>& board, int col,vector<vector<string>>& ans){
        if(col == board.size())
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<board.size();row++)
        {
            if(isSafe(row,col,board))
            {
                board[row][col]='Q';
                solve(board,col+1,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        string s(n,'.');
        for(int i=0;i<n;i++)
            board.push_back(s);
        
        vector<vector<string>> ans;
        solve(board,0,ans);
        return ans;
    }
};