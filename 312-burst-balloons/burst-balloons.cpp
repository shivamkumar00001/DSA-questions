class Solution {
public:

    vector<vector<int>> dp;
    int helper(vector<int> &nums, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=0;
        int ans=0;
        for(int k=i;k<=j;k++){
            ans = nums[i-1] * nums[k] * nums[j+1] + helper(nums, i,k-1)+helper(nums,k+1,j);
            maxi  = max(maxi,ans);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        dp.resize(nums.size()+2, vector<int>(nums.size()+2,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        return helper( nums, 1,nums.size()-2);
        
    }
};