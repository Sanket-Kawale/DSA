class Solution {
public:
// MOST OPTIMAL

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        // Convert rows of the matrices into arrays of binary integers
        vector<int> a(n, 0), b(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) a[i] |= (1 << j);
                if (img2[i][j] == 1) b[i] |= (1 << j);
            }
        }

        int max_overlap = 0;

        // Try all possible row and column offsets
        for (int row_shift = -n; row_shift < n; row_shift++) {
            for (int col_shift = -n; col_shift < n; col_shift++) {
                int current_overlap = 0;

                // Check overlap row by row using bitwise operations
                for (int i = 0; i < n; i++) {
                    // Ensure row index stays within bounds for the shift
                    if (i + row_shift < 0 || i + row_shift >= n) continue;

                    // Shift columns left or right depending on the sign
                    int shifted_row = (col_shift >= 0) ? (a[i] << col_shift) : (a[i] >> -col_shift);
                    
                    // Bitwise AND finds matching 1 bits instantly. __builtin_popcount counts them.
                    current_overlap += __builtin_popcount(shifted_row & b[i + row_shift]);
                }

                max_overlap = max(max_overlap, current_overlap);
            }
        }

        return max_overlap;
    }
};
