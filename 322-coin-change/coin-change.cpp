// class Solution {
// public:
//     vector<long long >dp;
//     int f(vector<int>& c, int x){
//         if(x == 0) return 0;
//         if(dp[x] !=-1) return dp[x];
//         int result = INT_MAX;
//         for(int i=0;i<c.size();i++){
//             if(x-c[i]<0) continue;
//             result = min(result, f(c, x-c[i]));
//         }
//         if(result == INT_MAX) return dp[x] = INT_MAX;
//         return dp[x] = result+1;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         dp.resize(amount+2,-1);
//         if(f(coins,amount) == INT_MAX) return -1;
//         else return f(coins,amount);
//     }
// };



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