class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)      return 1;
        if(n == 1)      return x;
        double ans = 1;
        double power = n;

        if(power < 0){
            x = 1/x;
            power = -power;
        }
        ans = myPow(x, power/2);

        if(n%2 == 0)    ans = ans*ans;
        if(n%2 != 0)    ans = x*ans*ans;

        
        return ans;
    }
};