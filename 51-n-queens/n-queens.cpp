class Solution {
public:
    void addSolution(vector<vector<char>> &board, vector<vector<string>> &ans){
    int n = board.size();
    vector<string> temp;

    for(int i = 0; i < n; i++){
        string row = "";
        for(int j = 0; j < n; j++){
            row.push_back(board[i][j]);
        }
        temp.push_back(row);
    }

    ans.push_back(temp);
}
    bool isSafe(int row, int col, vector<vector<char>> &board){
        int n = board.size();
        int x = row;
        int y = col;

        while(y>=0){
		if(board[x][y] == 'Q')	return false;
		y--;
	    }
        
        x = row;
        y = col;
        while(x>=0 && y>=0){
            if(board[x--][y--] == 'Q')  return false;
        }

        x = row;
        y = col;
        while(x<n && y>=0){
            if(board[x++][y--] == 'Q')  return false;
        }
        return true;
    }
    void solve(int col, vector<vector<char>> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            addSolution(board, ans);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';

                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char> (n,'.'));
        vector<vector<string>> ans;

        solve(0, board, ans, n);
        return ans;
    }
};