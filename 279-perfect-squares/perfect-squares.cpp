class Solution {
public:
    int helper( int n,vector<int>&dp){
        if(n==0) return 0;
        if( dp[n]!=-1) return dp[n];
        int result = INT_MAX ;
        for(int i=1;i*i<=n;i++){
            if(n-(i*i)<0) continue;
            result = min(result,1+helper((n-(i*i)) ,dp));
        }
        return dp[n] = result;
    }
    int numSquares(int n) {
        vector<int> dp(2*n,-1); 
        int count  =  helper(n,dp);
        return count == INT_MAX?n:count;
    }
};