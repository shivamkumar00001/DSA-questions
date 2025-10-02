class Solution {
public:
// recursive + memoization method 


    // vector<vector<int>> dp;
    // int helper( vector<vector<int>> & nums, int ind,int x){

    //     if(ind == nums.size()) return 0;
    //     int res =INT_MAX;
    //     if(dp[ind][x] != -1) return dp[ind][x];
    //     for(int i =x; i<nums[ind].size();i++){
    //         if(i-x>1) break;
    //         res = min(res, nums[ind][i]+helper(nums, ind+1,i));
    //     }
    //     return dp[ind][x] =res ;
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // dp.resize(n+5, vector<int>(triangle[n-1].size()+5,-1));   
        int n = triangle.size();

        vector<int> dp(triangle[n-1]);

        for(int row = n-2 ; row>=0;row--){
            for(int col = 0; col<=row ;col++){
                dp[col] = triangle[row][col] + min(dp[col] , dp[col+1]);
            }
        }
        return dp[0];
    }
};