class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        int i = 0;
        int sign = 1;
        long ans = 0;

        while(i<len && s[i] == ' '){
            i++;
        }

        if(i<len && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1:1;
            i++;
        }

        while(i<len && s[i] >= '0' && s[i] <= '9'){
            int digit = s[i]-'0';
            
            ans = (ans*10 + digit);
            if(ans*sign <= INT_MIN)       return INT_MIN;
            if(ans*sign >= INT_MAX)       return INT_MAX;
            i++;
        }

        return ans*sign;
    }
};