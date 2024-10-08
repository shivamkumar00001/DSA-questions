class Solution {
public:
    int power(long long v, long long n, long long mod) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return v % mod; 
        }

        long long half_power = power(v, n / 2, mod);
        if (n % 2 == 0) {

            return (half_power * half_power) % mod; 
        } else {
            return (half_power * half_power  * v ) % mod; 
        }
    } 

    int countGoodNumbers(long long n) {
        const long long mod = 1e9 + 7;
        
        long long even_positions = (n + 1) / 2; 
        long long odd_positions = n / 2;   

        long long even_count = power(5, even_positions, mod);
        long long odd_count = power(4, odd_positions, mod);
        
        return (even_count * odd_count) % mod;
    }
};
