class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }

        long power = n;
        double ans = 0;

        if(power < 0){
            x = 1/x;
            power = -power;
        }
        ans = myPow(x, power/2);

        if(n%2 == 0){
            ans = ans*ans;
        }
        else if(n%2 != 0){
            ans = x*ans*ans;
        }
        return ans;
    }
};