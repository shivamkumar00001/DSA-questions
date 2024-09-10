	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    long long int l = 1;
    long long int r = m;
    long long int mid;

    
    if (m == 1) {
        return 1;
    }

    
    auto power = [](long long int base, int exp, int limit) -> long long int {
        long long int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > limit) return limit + 1; // Return limit + 1 to signify overflow
        }
        return result;
    };

    while (l <= r) {
        mid = (l + r) / 2;
        long long int value = power(mid, n, m);

        if (value == m) {
            return mid;  
        } else if (value < m) {
            l = mid + 1;  
        } else {
            r = mid - 1;  
        }
    }

    return -1;  
	    
	}  
};
