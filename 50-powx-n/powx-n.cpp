class Solution {
public:
    double myPow(double x, int n) {
        
        double result=1;
        result=pow(x,n);
        /*
        while(n>0){
            if(n&1){
                result=result*x;
            }
            x=x*x;
            n=n>>1;
        }*/
        return result;
    }
};