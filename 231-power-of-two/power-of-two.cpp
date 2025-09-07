class Solution {
public:
    bool helper(double n){
        if(n==1) return true;
        if (n<1) return false;
        return helper(n/2.0);
    }
    bool isPowerOfTwo(int n) {
        double x = n;
        return helper(x);
    }
};