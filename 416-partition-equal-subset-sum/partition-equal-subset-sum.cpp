class Solution {
public:
    vector<vector<int>> dp;
  
    bool helper(int sum1, int sum2, vector<int>& nums, int i) {
        if (i == nums.size() && sum1 == sum2) return true;
        if (i == nums.size()) return false;

        if (dp[i][abs(sum1 - sum2)] != -1) 
            return dp[i][abs(sum1 - sum2)];

        if (helper(sum1 + nums[i], sum2, nums, i + 1)) 
            return dp[i][abs(sum1 - sum2)] = true;

        if (helper(sum1, sum2 + nums[i], nums, i + 1)) 
            return dp[i][abs(sum1 - sum2)] = true;

        return dp[i][abs(sum1 - sum2)] = false;
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        dp.assign(nums.size(), vector<int>(total + 1, -1));
        return helper(0, 0, nums, 0);
    }
};


// in this i learned how to put dp in one more way 