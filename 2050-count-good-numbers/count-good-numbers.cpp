class Solution {
public:
    
    long long pow (long long x, long long n){

        if( n == 1) return x;
        if( n == 0) return 1;

        long long ans = pow(x,n/2);

        if(n%2 == 0){
            return (ans*ans)%1000000007;
        }
        return (ans*ans*x)%1000000007;
    }
    int countGoodNumbers(long long n) {
        
       long long  e = (n+1)/2;
       long long  o = n/2;

       long long res = (pow(5,e) * pow(4,o))%1000000007;

       return res;
    }
};



// solve it using the power as there are total 5 even number and 4 prime numbers and then formula will be number of even places that is (n+1)/2 and the odd positions are n/2;  so answer is 5^(n+1)/2 * 4^n/2