class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<int> bits1, bits2;

        // 1. Convert 2D coordinates into simple 1D flattened integers
        // We use a factor of 100 to clearly separate row and column shifts
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) bits1.push_back(i * 100 + j);
                if (img2[i][j] == 1) bits2.push_back(i * 100 + j);
            }
        }

        // A simple frequency map to count how often each unique shift vector occurs
        unordered_map<int, int> shift_counts;
        int max_overlap = 0;

        // 2. Compare every '1' bit position from img1 against img2
        for (int b1 : bits1) {
            for (int b2 : bits2) {
                // The difference between their flattened values represents the precise shift
                int shift_vector = b2 - b1;
                
                shift_counts[shift_vector]++;
                max_overlap = max(max_overlap, shift_counts[shift_vector]);
            }
        }

        return max_overlap;
    }
};
