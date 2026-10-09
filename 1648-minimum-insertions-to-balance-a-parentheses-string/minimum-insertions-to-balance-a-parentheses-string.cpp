class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int right = 0;

        for(char ch : s){
            if(ch == '('){
                right += 2;
                if(right % 2 == 1){
                    ans++;
                    right--;
                }
            }
            else{
                right--;
                if(right < 0){
                    ans++;
                    right = 1;
                }
            }
        }
        return ans + right;
    }
};