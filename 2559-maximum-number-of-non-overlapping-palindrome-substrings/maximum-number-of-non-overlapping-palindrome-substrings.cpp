class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for(int length=1; length<=n; length++){
            for(int i=0; i+length-1 < n; i++){
                int j = i+length-1;

                if(length == 1){
                    palindrome[i][j] = true;
                }
                else if(length == 2){
                    palindrome[i][j] = (s[i] == s[j]);
                }
                else{
                    palindrome[i][j] = (s[i]==s[j] && palindrome[i+1][j-1]);
                }
            }
        }

        vector<int> dp(n+1, 0);

        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1];

            for(int start=0; start<i; start++){
                int length = i-start;

                if(length >= k && palindrome[start][i-1]){
                    dp[i] = max(dp[i], dp[start]+1);
                }
            }
        }
        return dp[n];
    }
};