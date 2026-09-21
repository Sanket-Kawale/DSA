class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool ans = 0;

        for(int i=0; i<=30; i++){
            long long temp = pow(2,i);

            if(temp == n){
                ans = 1;
            }
        }
        return ans;
    }
};