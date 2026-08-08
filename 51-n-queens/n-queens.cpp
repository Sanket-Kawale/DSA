class Solution {
public:
    bool isSafe(vector<string>board, int row, int col, int n){
        // three posibilities
        //upper diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q')    return false;
        }

        //left side of Q
        for(int j=col-1; j>=0; j--){
            if(board[row][j] == 'Q')    return false;
        }

        //lower diagonal
        for(int i=row+1, j=col-1; i<n && j>=0; i++, j--){
            if(board[i][j] == 'Q')    return false;
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