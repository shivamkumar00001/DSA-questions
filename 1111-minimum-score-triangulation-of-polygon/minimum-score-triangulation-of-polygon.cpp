class Solution {
public:
    vector<vector<int>>dp;
    long long helper( vector<int>& values, int i, int j){
        if(i == j ) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long  ans = INT_MAX;
        for(int k = i; k<j;k++){
            long long wt1 = helper(values, i, k);
            long long wt2 = helper(values, k+1, j);
            long long wt3 = values[i-1]*values[k]*values[j];
            ans = min(ans, wt1+wt2+wt3);
        }

        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        dp.resize(values.size(), vector<int>(values.size(),-1));
        return helper(values, 1, values.size()-1);
    }
};