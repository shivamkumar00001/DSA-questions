class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>prev(n,-1);
        vector<int>dp(n,1);
        int maxval=1;
        int last_idx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        prev[i] =j;
                    }

                    if(dp[i] >maxval){
                        maxval = dp[i];
                        last_idx = i;
                    }
                }
            }
        }

        vector<int>ans;

        while(last_idx!=-1){
            ans.push_back(nums[last_idx]);
            last_idx = prev[last_idx];
        }

        return ans;
    }
};