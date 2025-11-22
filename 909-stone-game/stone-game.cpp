class Solution {
public:
    // vector<vector<int>>dp;
    // int helper(vector<int>&piles, int i, int j){

    //     if(i==j) return piles[i];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return dp[i][j] = max(piles[i]-helper(piles,i+1,j), piles[j]-helper(piles, i, j-1));
    // }
    bool stoneGame(vector<int>& piles) {
        // dp.resize(piles.size()+5, vector<int>( piles.size()+5,-1));
        // int val = helper(piles,0,piles.size()-1);
        // return val>0;
        return true;
    }
};