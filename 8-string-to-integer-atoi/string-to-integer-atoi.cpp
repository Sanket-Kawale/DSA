class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        long ans = 0;
        int sign = 1;
        int i = 0;

        while(i<len && s[i] == ' '){
            i++;
        }
        if(i<len && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }

        while(i<len && s[i]>='0' && s[i]<='9'){
            int digit = s[i]-'0';

            ans = ans*10+digit;

            if(sign*ans <= INT_MIN)     return INT_MIN;
            else if(sign*ans >= INT_MAX)    return INT_MAX;

            i++;
        }

        return ans*sign;
    }
};