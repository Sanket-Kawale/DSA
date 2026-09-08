class Solution {
public:
    int countCommas(int n) {
        int start = 1000;
        int total = 0;
        while(start <= n){
            total = total + (n - start)+1;
            start = start*1000;     
        }
        return total;
    }
};