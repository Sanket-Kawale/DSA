#include <cmath>
#define pi 3.14
class Solution {
  public:
    long long int intersectionArea(long double X1, long double Y1, long double R1,
                                   long double X2, long double Y2, long double R2) {
        long double X = ( (X2-X1)*(X2-X1) + (Y2-Y1)*(Y2-Y1) );
        long double d = sqrt(X);
        long double add = R1+R2;
        long double sub = abs(R1-R2);
        long long int area = 0;
        
        if(d>=add){return 0;}
        else if(d<=sub){
            if(R1>R2){  area = pi*(R2*R2);  }
            else{   area = pi*(R1*R1); }
        }
        else{
            long double alpha = 2*acos( ((R1*R1) + (d*d) - (R2*R2)) / (2.0L*R1*d) );
            long double beta = 2*acos( ((R2*R2) + (d*d) - (R1*R1)) / (2.0L*R2*d) );
            
            long double area1 = 0.5 * (R1*R1) * ((alpha - sin(alpha)));
            long double area2 = 0.5 * (R2*R2) * ((beta - sin(beta)));
            area = area1 + area2;
        }
        return area;
    }
};