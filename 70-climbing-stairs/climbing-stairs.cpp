class Solution {
public:
    int helper(int n, int i,vector<int>&dp){
       if (i > n) return 0;   
        if (i == n) return 1; 
        if(dp[i]!=-1) return dp[i];
        return dp[i] = helper(n,i+1,dp)+helper(n,i+2,dp);
    }
    int climbStairs(int n) {
        // if(n == 1) return 1;

        // int pre1 = 1;
        // int pre2 = 2;
        // int curr =pre2;
        // for(int i =2;i<n;i++){
        //     curr = pre2 + pre1;
        //     pre1 = pre2 ;
        //     pre2 = curr ;
            
        // }
        // return curr;
        vector<int> dp(n,-1);
        return helper (n,0,dp);
    }
};