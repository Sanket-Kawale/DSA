class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int row = classroom.size();
        int col = classroom[0].size();
        int sr = 0, sc = 0, cnt = 0;

        vector<vector<int>> id(row, vector<int>(col, -1));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if(classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int full = (1 << cnt) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            row,
            vector<vector<vector<bool>>>(
                col,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        queue<array<int, 4>> q;
        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int moves = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if(mask == full)
                    return moves;

                if(e == 0)
                    continue;

                for(int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr < 0 || nr >= row || nc < 0 || nc >= col)
                        continue;

                    if(classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if(classroom[nr][nc] == 'R')
                        ne = energy;

                    if(classroom[nr][nc] == 'L')
                        nmask |= (1 << id[nr][nc]);

                    if(!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};