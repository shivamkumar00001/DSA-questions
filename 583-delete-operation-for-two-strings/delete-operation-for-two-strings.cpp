class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        // Base cases
        if (i == word1.size()) return word2.size() - j;
        if (j == word2.size()) return word1.size() - i;

        // Check memo
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);
        }

        // If not match → delete from either string
        return dp[i][j] = 1 + min(
            solve(i + 1, j, word1, word2, dp),   // delete from word1
            solve(i, j + 1, word1, word2, dp)    // delete from word2
        );
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solve(0, 0, word1, word2, dp);
    }
};