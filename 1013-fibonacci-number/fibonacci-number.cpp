class Solution {
public:
    int newFib(int n, vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = newFib(n-1, dp) + newFib(n-2, dp);
        return dp[n];
    } 
    int fib(int n) {
        vector<int> dp(n+1);
        for(int i=0; i<=n; i++){
            dp[i] = -1;
        }
        return newFib(n,dp);
    }
};