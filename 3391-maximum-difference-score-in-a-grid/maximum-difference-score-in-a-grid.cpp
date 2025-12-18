class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int helper(vector<vector<int>>& grid, int i, int j) {
        if (i >= m || j >= n) return INT_MIN / 2;

        if (dp[i][j] != INT_MIN) return dp[i][j];

        int best = INT_MIN;

        // move right
        if (j + 1 < n) {
            best = max(
                best,
                grid[i][j + 1] - grid[i][j] + max(0, helper(grid, i, j + 1))
            );
        }

        // move down
        if (i + 1 < m) {
            best = max(
                best,
                grid[i + 1][j] - grid[i][j] + max(0, helper(grid, i + 1, j))
            );
        }

        return dp[i][j] = best;
    }

    int maxScore(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, INT_MIN));

        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, helper(grid, i, j));
            }
        }
        return ans;
    }
};
