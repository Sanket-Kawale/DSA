class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> binary(n);
        int ans = 0;
        for (size_t i = 0; i < binary.size(); ++i) {
            if(binary[i] == 1)      ans++;
        }
        return ans;
    }
};