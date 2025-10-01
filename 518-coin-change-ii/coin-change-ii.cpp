class Solution {
public:
    
    vector<vector<int>> dp;
    int helper( int ind, vector<int> &coins, int k){
        if(ind == coins.size() && k!=0) return 0;

        if(k == 0) return 1;
        if(dp[k][ind]!=-1) return dp[k][ind];
        int res = 0;
        for(int i=ind;i<coins.size();i++){
            if(k-coins[i]<0) continue;
            res += helper(i, coins, k-coins[i]);
        }
        return dp[k][ind] =res;
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(5005,vector<int>(5005,-1));
        return helper(0, coins, amount);
    }
};