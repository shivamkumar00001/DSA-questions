class Solution {
public:
    vector<vector<int>> dp;

    int solve(int l, int r) {
        if (l >= r) return 0;         // no cost when searching 1 number
        if (dp[l][r] != -1) return dp[l][r];

        int ans = INT_MAX;

        for (int x = l; x <= r; x++) {
            int costLeft = solve(l, x - 1);
            int costRight = solve(x + 1, r);
            int worstCost = x + max(costLeft, costRight);

            ans = min(ans, worstCost);
        }

        return dp[l][r] = ans;
    }

    int getMoneyAmount(int n) {
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(1, n);
    }
};
