class Solution {
public:
     bool helper(double n){
        if(n==1) return true;
        if (n<1) return false;
        return helper(n/3.0);
    }
    bool isPowerOfThree(int n) {
        double x = n;
        return helper(n);
    }
};