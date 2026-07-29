class Solution {
public:
    vector<string> solve(vector<string> &ans, string curr, int open, int close, int n){
        
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return ans;
        }

        if(open < n){
            ans = solve(ans, curr+'(', open+1, close, n);
        }
        if(close < open){
            ans = solve(ans, curr+')', open, close+1, n);
        }

        return ans;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        ans = solve(ans, "", 0, 0, n);

        return ans;
    }
};