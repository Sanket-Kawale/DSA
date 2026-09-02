class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> sbit(start);
        bitset<32> gbit(goal);
        int ans = 0;

        if(start == goal)    return ans;

        for(int i=0; i<gbit.size(); ++i){
            if(sbit[i] == gbit[i]){
                continue;
            }
            if(sbit[i] != gbit[i]){
                sbit[i] = !sbit[i];
                ans++;
            }
        }

        return ans;
    }
};