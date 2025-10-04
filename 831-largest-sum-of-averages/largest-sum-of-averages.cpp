class Solution {
public:
    double dp[105][105];
    double helper (vector<int> &nums, int k, int ind){
        
        if(ind >= nums.size()) return 0;

        if(k == 0) return INT_MIN;

        if(dp[ind][k]!= 0) return dp[ind][k];
        double sum = 0;
        double ans =0;
        for(int i = ind ; i<nums.size();i++){
            sum += nums[i];

            ans = max (ans, sum/((i-ind+1)*1.0)+ helper(nums, k-1, i+1));
        }
        return dp[ind][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        
        memset(dp,0,sizeof(dp));
        return helper(nums, k, 0);
    }
};