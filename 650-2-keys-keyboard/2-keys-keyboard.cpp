class Solution {
public:
    int dp[1001][1001];
    
    int helper(int n, int original, int copy) {
        if (original == n) return 0;
        if (original > n) return 1e9;
        
        if (dp[original][copy] != -1) return dp[original][copy];
        
        int ans = 1e9;
        
        
        if (copy > 0) {
            ans = min(ans, 1 + helper(n, original + copy, copy));
        }
        
        if(original != copy)
        ans = min(ans, 1 + helper(n, original, original));
        
        return dp[original][copy] = ans;
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        memset(dp, -1, sizeof(dp));
        return helper(n, 1, 0);
    }
};
