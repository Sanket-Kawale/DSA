class Solution {
public:
    //Using 1d DP
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<unsigned long long>dp(n+1, 0);
        dp[0] = 1;  //empty string, base condition

        for(int i=0; i<m; i++){
            for(int j=n-1; j>=0; j--){//traversing t: r -> l
                if(s[i] == t[j]){       //if matching
                    dp[j+1] += dp[j];
                }
            }
        }
        return dp[n];
    }
};