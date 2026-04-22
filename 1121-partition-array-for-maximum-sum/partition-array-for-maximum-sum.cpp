class Solution {
public:
    
    vector<int>dp;
    int helper( vector<int> &arr, int k, int i, int j){
         
         if(i == arr.size()) return 0;
         
         if(dp[i] != -1) return dp[i];
         int maxi =0;
         int l =i;
         int res =0;
         while(l<arr.size() && j>0){
            int ans = helper( arr, k,l+1,k);
            maxi = max(arr[l],maxi);
            j--;
            res = max (res, (maxi*(k-j))+ans);
            l++;
         }
         return dp[i] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return helper(arr,k,0,k);
    }
};








