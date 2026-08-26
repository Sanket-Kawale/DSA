class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        
        if(!s.contains("1"))         return "";
        for(int i=0; i<s.length(); i++){
            string temp = "";
            int dummy = k;
            int j = i;

            while(dummy != 0 && j<s.length()){
                char ch = s[j];
                temp.push_back(ch);
                if(ch == '1'){
                    dummy--;
                }
                j++;
            }
            if(dummy == 0){
                if(ans.empty() || temp.length()<ans.length() || (temp.length()==ans.length() && temp < ans)){
                    ans.clear();
                    ans.append(temp);
                }
            }
        }
        return ans;
    }
};