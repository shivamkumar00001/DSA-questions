class Solution {
public:
    vector<vector<int>> dp;

    int helper(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if(i >= m || j >= n) return INT_MAX;

        // Destination
        if(i == m-1 && j == n-1) return grid[i][j];

        // Memoized answer
        if(dp[i][j] != -1) return dp[i][j];

        // Choose min path: go right or down
        int right = helper(grid, i, j+1);
        int down = helper(grid, i+1, j);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        return helper(grid, 0, 0);
    }
};
