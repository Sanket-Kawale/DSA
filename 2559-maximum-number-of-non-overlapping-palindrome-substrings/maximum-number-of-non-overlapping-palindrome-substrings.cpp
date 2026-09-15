class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;
        int start = 0;

        while(start + k <= n) {
            bool found = false;

            // Check palindrome of length k
            int left = start;
            int right = start + k - 1;

            while(left < right && s[left] == s[right]) {
                left++;
                right--;
            }

            if(left >= right) {
                ans++;
                start += k;
                found = true;
                continue;
            }

            // Check palindrome of length k + 1
            if(start + k + 1 <= n) {
                left = start;
                right = start + k;

                while(left < right && s[left] == s[right]) {
                    left++;
                    right--;
                }

                if(left >= right) {
                    ans++;
                    start += k + 1;
                    found = true;
                    continue;
                }
            }

            if(!found)
                start++;
        }

        return ans;
    }
};