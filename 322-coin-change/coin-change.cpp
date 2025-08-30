class Solution {
public:
    vector<int >dp;

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+2,-1);
       
        dp[0] = 0;

        for(int i = 1 ;i<=amount;i++){
            int result = INT_MAX;

            for(int j = 0 ;j<coins.size();j++){
                if(i-coins[j]<0) continue;
                result = min(result, dp[i-coins[j]]);
            }
            if(result == INT_MAX) dp[i] = INT_MAX;
            else dp[i] = 1+result;
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};