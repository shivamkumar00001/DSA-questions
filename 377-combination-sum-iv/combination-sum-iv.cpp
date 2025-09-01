class Solution {
public:
    vector<int> dp;
    int f(vector<int>nums , int t){
        if(t == 0) return 1;
        if(dp[t] !=-1) return dp[t];
        int result =0;
        for(int i=0;i<nums.size();i++){
            if(t-nums[i]<0) continue;
            result+= f(nums, t-nums[i]);
        }
        return dp[t] = result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+5,-1);
        return f(nums,target);
    }
};