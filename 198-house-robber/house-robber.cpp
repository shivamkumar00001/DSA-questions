class Solution {
public:
    
    int f(vector<int>&arr, int i,vector<int>& dp){
        if(i == arr.size()-1) return arr[i];
        if(i == arr.size()-2) return max(arr[i+1],arr[i]);
        if(dp[i] != -1) return dp[i];
        return dp[i] = max((arr[i]+f(arr,i+2,dp)),(0+f(arr,i+1,dp)));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

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