class Solution {
public:
    int longestSubsequence(vector<int>& nums, int k) {
        unordered_map<int,int> dp;

        int ans =INT_MIN;
        for(auto x : nums){
            dp[x] = 1+ dp[x-k];
            ans = max(ans,dp[x]);
        }

        return ans;
    }
};