class Solution {
public:
    vector<vector<int>> dp;

    int helper(string &text1, string &text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        if (text1[i] == text2[j]) {
            res = 1 + helper(text1, text2, i + 1, j + 1);
        } else {
            res = max(helper(text1, text2, i + 1, j),
                      helper(text1, text2, i, j + 1));
        }

        return dp[i][j] = res;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return helper(text1, text2, 0, 0);
    }
};
