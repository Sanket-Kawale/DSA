class Solution {
  private:
    bool isSafe(vector<vector<int>>& maze, int n, int newx, int newy, 
                vector<vector<int>> visited){
                    if(newx >= 0 && newx < n && newy >= 0 && newy < n && 
                       visited[newx][newy] == 0 && maze[newx][newy] == 1){
                           return true;
                       }
                    else{
                           return false;
                       }
                       
                }
    void solve(vector<vector<int>>& maze, int n, int x, int y, vector<string> &ans, 
               vector<vector<int>> visited, string path){
                   //reached x,y
                   //base case
                   if(x == (n-1) && y == (n-1)){
                       ans.push_back(path);
                       return;
                   }
                   
                   visited[x][y] = 1;
                   
                   //4 choices --> up,down,left,right
                   //down
                   int newx = x+1;
                   int newy = y;
                   if(isSafe(maze, n, newx, newy, visited)){
                       path.push_back('D');
                       solve(maze,n,newx,newy,ans,visited,path);
                       path.pop_back();
                   }
                   //left
                   newx = x;
                   newy = y-1;
                   if(isSafe(maze, n, newx, newy, visited)){
                       path.push_back('L');
                       solve(maze,n,newx,newy,ans,visited,path);
                       path.pop_back();
                   }
                   //up
                   newx = x-1;
                   newy = y;
                   if(isSafe(maze, n, newx, newy, visited)){
                       path.push_back('U');
                       solve(maze,n,newx,newy,ans,visited,path);
                       path.pop_back();
                   }
                   //right
                   newx = x;
                   newy = y+1;
                   if(isSafe(maze, n, newx, newy, visited)){
                       path.push_back('R');
                       solve(maze,n,newx,newy,ans,visited,path);
                       path.pop_back();
                   }
                   
                   
                   
                   
                   
                   
                   
                   visited[x][y] = 0;  //backtracking
               }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze ) {
        vector<string> ans;
        int n = maze.size();
        int srcx = 0;
        int srcy = 0;
        if(maze[0][0] == 0){
            return ans;
        }
        vector<vector<int>> visited = maze;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
        string path = "";
        solve(maze,n,srcx,srcy,ans,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};