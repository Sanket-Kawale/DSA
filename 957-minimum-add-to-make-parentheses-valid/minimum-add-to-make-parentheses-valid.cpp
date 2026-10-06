class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            if(ch == '('){
                open += 1; 
            }
            else {
                if(open > 0) {
                    open--;
                }
                else {
                    ans++;
                }
            }
        }
        return ans + open;
    }
};