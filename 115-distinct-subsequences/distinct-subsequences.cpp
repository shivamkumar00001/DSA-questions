class Solution {
public:
    
    vector<vector<long long>> dp;

    long long helper(string &s, string &t, int i, int j){

        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        long long ans = 0;

        if(s[i] == t[j]){
            ans += helper(s, t, i+1, j+1);
        }
        ans += helper(s, t, i+1, j);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        
        dp.assign(s.size(), vector<long long>(t.size(), -1));
        return helper(s, t, 0, 0);
    }
};