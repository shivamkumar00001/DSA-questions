class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <=2) return n;

        vector<vector<int>> dp(k,vector<int>(n,1));
        int maxval = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {

                int mod = (nums[i]+nums[j])%k;
                dp[mod][i] = max(dp[mod][i], dp[mod][j] + 1);
                maxval = max(maxval, dp[mod][i]);

            }
        }
        return maxval;
    }
};
