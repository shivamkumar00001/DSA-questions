class Solution {
public:
    int dp [10005][105][2];

    int helper(vector<int> & prices, int i, int k, bool on){
        
        if(i == prices.size() ) return 0;
        if(dp[i][k][on] !=-1) return dp[i][k][on];
        int ans = INT_MAX;

        ans = helper(prices, i+1, k, on);

        if(on){
            ans = max({ans,helper(prices, i+1,k, false)-prices[i]});
        }
        else{
            if(k>0){
                  ans = max(ans, helper(prices, i+1,k-1, true)+prices[i]);
            }
        }
        return dp[i][k][on] =ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp , -1, sizeof dp);
        int i =0;
        bool on =true;
        return helper(prices, i, k, on) ; 
    }
};