class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> match(n);
        vector<int> st;

        // Find matching brackets
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push_back(i);
            }
            else if(s[i] == ')') {
                int j = st.back();
                st.pop_back();

                match[i] = j;
                match[j] = i;
            }
        }

        string ans = "";
        int i = 0;
        int dir = 1;

        while(i < n) {
            if(s[i] == '(' || s[i] == ')') {
                i = match[i];
                dir = -dir;
            }
            else {
                ans += s[i];
            }

            i += dir;
        }

        return ans;
    }
};