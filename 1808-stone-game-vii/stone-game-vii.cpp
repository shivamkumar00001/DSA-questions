class Solution {
public:
     vector<vector<int>>dp;
     vector<int>prefix;

     int ans =0;
    int helper(vector<int>&piles, int i, int j){

        if(i==j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int val1 = prefix[j+1] - prefix[i+1];
        int val2 = prefix[j]-prefix[i];
        return dp[i][j] = max(val1- helper(piles, i+1,j), val2 - helper(piles, i , j-1));
    }
    int stoneGameVII(vector<int>& piles) {
        dp.resize(piles.size()+5, vector<int>( piles.size()+5,-1));
         prefix.resize(piles.size()+1, 0);
        for(int i=1;i<=piles.size();i++){
            prefix[i] = prefix[i-1]+piles[i-1];
        }

        return helper(piles, 0, piles.size()-1);
    }
};