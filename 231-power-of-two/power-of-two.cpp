class Solution {
public:
    // bool helper(double n){
    //     if(n==1) return true;
    //     if (n<1) return false;
    //     return helper(n/2.0);
    // }
    bool isPowerOfTwo(double n) {
         if(n == 1) return true;
         if(n  < 1) return false;

         return isPowerOfTwo(n/2.0);
    }
};