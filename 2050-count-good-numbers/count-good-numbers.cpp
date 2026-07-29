class Solution {
public:
    const long long MOD = 1000000007;

    long long solve(long long x, long long n){
        long long ans = 0;
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        ans = solve(x, n/2);
        if(n % 2 == 0)      ans = (ans * ans) % MOD;
        else if(n % 2 != 0) ans = ((x*ans) % MOD *ans)%MOD;

        return ans % MOD;
    }
    int countGoodNumbers(long long n) {
        int result = 0;

        long long even = (n+1)/2;
        long long odd = n/2;

        long long first = solve(5, even);
        long long second = solve(4, odd);

        result = (first * second) % MOD;

        return result;
    }
};