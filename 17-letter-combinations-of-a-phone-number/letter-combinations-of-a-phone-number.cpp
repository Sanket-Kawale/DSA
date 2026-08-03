class Solution {
public:
    void solve(string digits, vector<string> &ans, string output, 
                int index, string mapping[10]){
        
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value =  mapping[number];

        for(int i=0; i<value.size(); i++){
            output.push_back(value[i]);
            solve(digits, ans, output, index+1, mapping);
            output.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        int index = 0;
        string mapping[10];

        if(digits.length() == 0){
            return ans;
        }

        mapping[0] = "";
        mapping[1] = "";
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        solve(digits, ans, output, index, mapping);

        return ans;
    }
};