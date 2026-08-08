class Solution {
public:
    bool isSafe(vector<string>board, int row, int col, int n){
        // three posibilities
        int dupRow = row;
        int dupCol = col;
        //upper diagonal
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q')    return false;
            row--;
            col--;
        }

        //left side of Q
        row = dupRow;
        col = dupCol;
        while(col >= 0){
            if(board[row][col] == 'Q')    return false;
            col--;        
        }

        //lower diagonal
        row = dupRow;
        col = dupCol;
        while(row<n && col>=0){
            if(board[row][col] == 'Q')    return false;
            row++;
            col--;
        }

        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string>board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(board, row, col, n)){         //is it safe to place queen
                board[row][col] = 'Q';
                solve(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);        //n*n chess board
        string s(n, '.');               //initialize string by dummy val & size=n 

        for(int i=0; i<n; i++){
            board[i] = s;               //all board with '.'
        }

        solve(0, ans, board, n);        //only colummn needed
        return ans;
    }
};