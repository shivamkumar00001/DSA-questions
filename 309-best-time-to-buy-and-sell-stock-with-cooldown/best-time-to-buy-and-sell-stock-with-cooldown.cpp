class Solution {
public:
    vector<vector<int>> dp;
    int helper( vector<int>& prices, int ind , bool on){
        if(ind >= prices.size()) return 0;
        if(dp[ind][on] !=-1) return dp[ind][on];
        int profit = INT_MIN;
        if(on){
            profit = max((helper(prices, ind+1, false)- prices[ind]),helper(prices, ind+1, true));
        }

        else {
            profit = max((helper(prices, ind+2, true) + prices[ind]),helper(prices, ind+1, false));
        }
        return dp[ind][on] = profit;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+5, vector<int>(5, -1));
        return helper(prices, 0, true);
    }
};