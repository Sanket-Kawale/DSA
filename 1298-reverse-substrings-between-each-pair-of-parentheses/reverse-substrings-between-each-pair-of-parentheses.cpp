class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> stack;
        int n = s.length();

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                stack.push_back(i);
            }
            else if(s[i] == ')'){
                int start = stack.back();
                stack.pop_back();

                reverse(s.begin()+start+1, s.begin()+i);
            }
        }

        string ans = "";
        for(char ch : s){
            if(ch != '(' && ch != ')'){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};