class Solution {
public:
    int countCommas(int n) {
        if(n < 1000){
            return 0;
        }

        int ans = 0;
        int digit = 1;
        int temp = n;
        while(temp >= 1000){
            temp = n - 1000;
            ans = temp+1;
        }
        return ans;
    }
};