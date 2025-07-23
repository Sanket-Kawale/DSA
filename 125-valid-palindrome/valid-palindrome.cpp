class Solution {
public:

    char toLower(char ch){
        if(ch >= 'a' && ch <= 'z'){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool validate(char ch){
        if( (ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9') ){
                return 1;
            }
            return 0;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = n-1;
        while(start < end){
            if(!validate(s[start])){
                start++;
            }
            else if(!validate(s[end])){
                end--;
            }
            else if(toLower(s[start]) != toLower(s[end])){
                return 0;
            }
            else{
                start++;
                end--;
            }
        }
        return 1;
    }
};