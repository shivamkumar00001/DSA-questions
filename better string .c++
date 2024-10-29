class Solution {
public:
    long long countUniqueSubsequences(string &str) {
        int n = str.size();
        vector<long long> dp(n + 1, 0);  // dp[i] stores the number of unique subsequences ending at i
        unordered_map<char, int> lastOccurrence;  // Tracks last occurrence of each character
        dp[0] = 1;  // Empty subsequence

        for (int i = 1; i <= n; ++i) {
            char current = str[i - 1];
            dp[i] = 2 * dp[i - 1];  // Every subsequence can either include or exclude current character

            // If current character has appeared before, subtract sequences that end at the previous occurrence
            if (lastOccurrence.find(current) != lastOccurrence.end()) {
                dp[i] -= dp[lastOccurrence[current]];
            }

            // Update last occurrence of current character
            lastOccurrence[current] = i - 1;
        }

        // Total unique subsequences, excluding the empty one
        return dp[n] - 1;
    }

    string betterString(string str1, string str2) {
        long long count1 = countUniqueSubsequences(str1);
        long long count2 = countUniqueSubsequences(str2);
        return (count1 >= count2) ? str1 : str2;
    }
};
