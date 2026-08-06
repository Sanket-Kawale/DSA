class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int index){

        int row = board.size();
        int col = board[0].size();

        if(index == word.length()){     //base condition
            return true;
        }
        if(i<0 || i>=row || j<0 || j>=col){     //invalid
            return false;
        }
        if(board[i][j] != word[index]){         //invalid
            return false;
        }

        char temp = board[i][j];                //mark curr visited
        board[i][j] = '#';

        bool found = 
        solve(board, word, i, j+1, index+1) ||      //right
        solve(board, word, i, j-1, index+1) ||      //left
        solve(board, word, i+1, j, index+1) ||      //down
        solve(board, word, i-1, j, index+1);        //up

        board[i][j] = temp;                      //backtrack

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                char temp = word[0];

                if(board[i][j] == temp){
                    if(solve(board, word, i, j, 0))
                    return true;
                }
            }
        }
        return false;
    }
};