// USING RECURSION + MEMOISATION
class Solution {
public:
    int m, n;
    int t[101][101][201];

    bool solve(int i, int j, int openCount, vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();

        openCount += (grid[i][j]=='(') ? 1 : -1;
        
        if(openCount < 0)       return false;

        if(t[i][j][openCount] != -1){
            return t[i][j][openCount];
        }
    
        if(i==row-1 && j==col-1)    return t[i][j][openCount] = (openCount==0);

        if(i < row - 1){
            if(solve(i+1, j, openCount, grid) == true){
                return t[i][j][openCount] = true;        //move down
            }
        }
        if(j < col-1){
            if(solve(i, j+1, openCount, grid) == true){
                return t[i][j][openCount] = true;        //move right
            }
        }
        return t[i][j][openCount] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == ')' || grid[m-1][n-1] == '(')       return false;
        if((m+n-1) % 2 != 0) return false;

        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, grid);
    }
};