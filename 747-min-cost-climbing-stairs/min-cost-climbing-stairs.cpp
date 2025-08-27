class Solution {
public:
    int helper(vector<int>&cost , int i,vector<int>& dp){
        if( i == cost.size()-1 || i == cost.size()-2) return cost[i];
        if(dp[i] !=-1) return dp[i];
        return dp[i] = cost[i] + min(helper(cost,i+1,dp),helper(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(helper(cost,0,dp),helper(cost,1,dp));

    }
};