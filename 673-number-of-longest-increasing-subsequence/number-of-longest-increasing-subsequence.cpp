class Solution {
public:
  

    int findNumberOfLIS(vector<int>& nums) {
        
       int n = nums.size();

       vector<pair<int,int>>dp(n+1,{1,1});
       int maxval = 1;
       for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                int x = dp[i].first;
                int z = dp[j].first;

                if(z+1 == x){
                    dp[i].second +=dp[j].second;
                }
                else if(z+1>x){
                  dp[i].first = max(dp[i].first,dp[j].first+1);
                  maxval = max(maxval,dp[i].first);
                  dp[i].second = dp[j].second;
                }
            }
        }
       }
       int count =0;
       for(int i =0;i<n;i++){
        if(dp[i].first == maxval) count+= dp[i].second;
       }
      return count;
    }
};