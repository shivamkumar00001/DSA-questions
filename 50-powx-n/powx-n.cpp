class Solution {
public:
    double helper(double x, long long  n){
        if(n == 1) return x;
        if(n == 0) return 1;
        double ans = myPow(x,n/2);;
        if(n%2 == 0){
           return ans*ans;}
        else {
            return ans*ans*x;
        }
        
    }
    double myPow(double x, int n) {
       long long  b = n;
       b = (-1*b);
       if(n>=0){
        return helper(x,n);
       }
       else return (double)(1)/(double)(helper(x,b));
    }
};