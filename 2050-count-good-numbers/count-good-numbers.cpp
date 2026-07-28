class Solution {
public:

    const long long MOD = 1000000007;

    long long power(long long x, long long n){

        if(n == 0)
            return 1;

        long long ans = power(x, n / 2);

        // Even power
        if(n % 2 == 0)
            return (ans * ans) % MOD;

        // Odd power
        return (((x * ans) % MOD) * ans) % MOD;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long first = power(5, even);
        long long second = power(4, odd);

        return (first * second) % MOD;
    }
};