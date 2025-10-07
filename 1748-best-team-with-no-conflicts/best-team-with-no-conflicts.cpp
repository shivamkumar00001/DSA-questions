class Solution {
public:
    vector<vector<int>> dp;

    int helper(vector<pair<int,int>> &as, int prev, int i) {
        if (i == as.size()) return 0;

        if (dp[prev + 1][i] != -1) return dp[prev + 1][i];

        int ans = 0;

        // Option 1: include current player if valid
        if (prev == -1 || as[prev].second <= as[i].second) {
            ans = max(ans, as[i].second + helper(as, i, i + 1));
        }

        // Option 2: skip current player
        ans = max(ans, helper(as, prev, i + 1));

        return dp[prev + 1][i] = ans;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> as;
        for (int i = 0; i < scores.size(); i++) {
            as.push_back({ages[i], scores[i]});
        }

        sort(as.begin(), as.end()); // sort by age, then score automatically

        dp = vector<vector<int>>(as.size() + 1, vector<int>(as.size(), -1));

        return helper(as, -1, 0);
    }
};
