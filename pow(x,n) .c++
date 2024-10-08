class Solution {
public:
    
     double power(double x, long long n){
         
         if(n==0){
            return 1;
         }

         if(n==1){
            return (x);
         }

        double v= power (x,n/2);

         if(n%2==0){
            return (v*v);
         }
         else {
            return (v*v*x);
         }
    }


    double myPow(double x, int n) {
        
        long long  b=n;
        if(n>0){
        return  power(x,n);
        }
        else{
             b = (-1*b);
            return double(1)/double(power(x,b));
        }
    }
};
