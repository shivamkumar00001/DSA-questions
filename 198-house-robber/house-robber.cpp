class Solution {
public:
    vector<int> dp;
    int helper(vector<int>&nums, int n){
        if(n == 1)return max(nums[1],nums[0]);
        if(n==0) return nums[0];
        
        if(dp[n] != -1) return dp[n];
        int a = helper(nums, n-1);
        int b = helper(nums,n-2)+nums[n];

        return dp[n] = max(a,b);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return helper( nums ,nums.size()-1);
        
    }
};

// dp[i] = max(dp[i-1], dp[i-2]+nums[i]);