class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>&nums, int& time, int val, int ind){

        if(val >= time) return 0;
        if(ind == nums.size()) return INT_MAX/2;
        if(dp[val][ind]!=-1) return dp[val][ind];
        int ans = INT_MAX;
        int start = nums[ind][0], end = nums[ind][1];

            
        if (start <= val && end > val)
        ans = min(ans, 1+helper(nums,time, end, ind+1));

        ans = min(ans, helper(nums,time,val, ind+1));

        return dp[val][ind] = ans;
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        dp.resize(200, vector<int>(200,-1));
        sort(clips.begin(),clips.end());
        int ans = helper(clips, time, 0, 0);
        if(ans == INT_MAX/2) return -1; 
        return ans;
    }
};