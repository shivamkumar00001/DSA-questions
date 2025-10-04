class Solution {
public:
     const int MOD = 1e9 + 7;
       int dp[5001][7][16];
    int helper(int n,  vector<int>&nums, int last,int count){
        if( n == 0 ) return 1;
        if(dp[n][last+1][count] != -1) return dp[n][last+1][count];
        long long  ans =0;
        for(int i =0;i<6;i++){

            if(i == last){
            if(count<nums[i]){
                ans += helper(n-1, nums,i,count+1);
            }
            }
            else ans += helper(n-1, nums,i,1);

            ans%= MOD;
        }
        return dp[n][last+1][count] =ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        
        memset(dp, -1, sizeof(dp));
        return helper(n, rollMax, -1,0);
    }
};