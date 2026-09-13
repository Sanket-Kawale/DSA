class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int row_shift = -n; row_shift < n; row_shift++){
            for(int col_shift = -n; col_shift < n; col_shift++){
                vector<vector<int>> temp(n, vector<int>(n, 0));
                
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(img1[i][j] == 1){
                            int new_i = i + row_shift;
                            int new_j = j + col_shift;
                            if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
                                temp[new_i][new_j] = 1;
                            }
                        }
                    }
                }

                int current_overlap = 0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(temp[i][j] == 1 && img2[i][j] == 1){
                            current_overlap = current_overlap + 1;
                        }
                    }
                }
            
                ans = max(ans, current_overlap);
            }
        }
        
        return ans;
    }
};
