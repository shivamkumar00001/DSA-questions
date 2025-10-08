class Solution {
public:
    
    vector<vector<int>>dp;
    int helper( vector<int>& prices, int ind, int reward){

        if(ind  == prices.size()) return 0;
        if(dp[ind][reward]!= -1) return dp[ind][reward];
        int ans = INT_MAX;
        if(reward>0){
            ans = min(ans, helper(prices, ind+1, reward-1));
        }
        ans = min(ans, prices[ind]+ helper(prices,ind+1,ind+1));

        return dp[ind][reward]= ans;
    }
    int minimumCoins(vector<int>& prices) {
        
        dp.resize(prices.size()+1,vector<int>(prices.size()+1,-1 ));
        return helper( prices, 0, 0);
    }
};