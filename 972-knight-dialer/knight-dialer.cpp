class Solution {
public:
    int dp[4][3][5001];
    vector<vector<int>> moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    const int MOD = 1e9 + 7;
    
    bool valid(int i, int j) {
        if (i < 0 || i > 3 || j < 0 || j > 2) return false;
        if (i == 3 && (j == 0 || j == 2)) return false;
        return true;
    }
    
    int helper(int i, int j, int n) {
        if (!valid(i, j)) return 0;
        if (n == 1) return 1;
        if (dp[i][j][n] != -1) return dp[i][j][n];
        
        long long res = 0;
        for (auto &m : moves) {
            int ni = i + m[0];
            int nj = j + m[1];
            if (valid(ni, nj))
                res = (res + helper(ni, nj, n - 1)) % MOD;
        }
        return dp[i][j][n] = res;
    }
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        long long ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (valid(i, j))
                    ans = (ans + helper(i, j, n)) % MOD;
            }
        }
        return ans;
    }
};
