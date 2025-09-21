class Solution {
public:
    // recursion + memoization method

   int f (vector<int> &nums, int i, vector<int> &dp){
    if (i==nums.size()-2){
        return max(nums[i],nums[i+1]);
    }
    if(i == nums.size()-1){
        return nums[i];
    }
    if(nums.size() ==1) return nums[i];

    if(dp[i] != -1) return dp[i];
    int sum1 = f(nums, i+1, dp);
    int sum2 = nums[i] + f(nums, i+2, dp);

    return dp[i] = max(sum1,sum2);
   }
    int rob(vector<int>& nums) {
        int n = nums.size();




         //tabulation method




        // if(n == 1) return nums[0];
        // if(n == 2) return max(nums[0],nums[1]);

        // int amount =0;
        vector<int>dp(n,-1);
        // dp[0] = nums[0];
        // dp[1] = nums[1];
        // for(int i = 2 ;i<n;i++){
        //     dp[i] = max(nums[i]+(dp[i-1]-nums[i-1]),(nums[i] + dp[i-2])); 
        // }

        // return max(dp[n-1],dp[n-2]);
         
        return f(nums,0,dp);
    }
};