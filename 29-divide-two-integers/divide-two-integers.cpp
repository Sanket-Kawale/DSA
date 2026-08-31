class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 2147483647 && divisor == -1){
            return -2147483647;
        } 
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        long long temp = 0;
        long long a = dividend;
        long long b = divisor;
        int sign = 1;
        int ans = 0;

        if(a < 0 && b < 0){
            a = -a;
            b = -b;
        }
        else if(a < 0){
            sign = -1;
            a = -a;
        }
        else if(b < 0){
            sign = -1;
            b = -b;
        }

        for(long long i = 1; i <= INT_MAX; i++){
            temp += b;

            if(temp <= a){
                ans = i;
            }

            if(temp > a){
                break;
            }
        }

        if(sign == -1)
            return -ans;

        return ans;
    }
};