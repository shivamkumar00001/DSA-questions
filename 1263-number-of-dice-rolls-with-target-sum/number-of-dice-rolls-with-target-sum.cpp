class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<int>>dp;
    long long f(int n, int k, int x){
        if(n==0) return (x==0);
        if(x<0) return 0;
        if(dp[n][x]!=-1) return dp[n][x];
        long long result =0;
            for(int j=1;j<=k;j++){
                result = (result + f(n-1, k, x-j)) % mod;
            }
   
        return dp[n][x] =result;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n + 1, vector<int>(target + 1, -1));
        return f(n,k, target);
    }
};