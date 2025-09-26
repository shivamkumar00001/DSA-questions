class Solution {
public:
    vector<vector<int>> dp;
    int helper( vector<int> & nums, int i, int j){

        if(i== j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(nums[i]-helper(nums,i+1,j), nums[j]-helper(nums, i, j-1));
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int i =0;
        int j = nums.size()-1;
        dp.resize(j+2, vector<int>(j+2,-1));
        int val = helper(nums, i, j);
        if(val>=0) return true;
        return false;
    }
};