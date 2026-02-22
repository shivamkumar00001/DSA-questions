class Solution {
public:
    bool isPowerOfFour(double n) {
        if(n == 1) return true;
        if( n< 1) return false;

        return isPowerOfFour(n/4.0);
    }
};