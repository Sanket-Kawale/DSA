class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> last(26, 0);

        long long total = 0;

        for(char ch : s) {
            int c = ch - 'a';
            long long newSubseq = (total + 1) % MOD;
            total = (total + newSubseq - last[c] + MOD) % MOD;

            last[c] = newSubseq;
        }

        return total;
    }
};