class Solution {
public:
    int dp[110][110][610];

    int helper(vector<pair<int,int>>& count, int m, int n, int ind) {
        if (ind == count.size()) return 0;
        if (dp[m][n][ind] != -1) return dp[m][n][ind];

        int ans = helper(count, m, n, ind + 1); 
        int c0 = count[ind].first;
        int c1 = count[ind].second;

        if (m >= c0 && n >= c1)
            ans = max(ans, 1 + helper(count, m - c0, n - c1, ind + 1));

        ans = max(ans, helper(count, m, n, ind+1));

        return dp[m][n][ind] = ans;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int,int>> count;

        for (auto& s : strs) {
            int c0 = 0, c1 = 0;
            for (char ch : s) {
                if (ch == '0') c0++;
                else c1++;
            }
            count.push_back({c0, c1});
        }

        return helper(count, m, n, 0);
    }
};
