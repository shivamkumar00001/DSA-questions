class Solution {
public:
    vector<vector<int>>dp;
    int maxi (vector<int>& arr, int a, int b){
        int ma = INT_MIN;

        for(int i =a;i<=b;i++){
            ma = max(ma,arr[i]);
        }
        return ma;
    }
    int helper(vector<int>& arr, int i, int j){

        if(i==j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k<j;k++){
            int cost1 = helper(arr, i, k);
            int cost2 = helper(arr, k+1, j);
            int cost3 = maxi(arr,i,k)*maxi(arr,k+1,j);
            ans = min(ans, cost3+cost2+cost1);
        }
        return dp[i][j] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        dp.resize(arr.size(), vector<int>(arr.size(),-1));
        return helper(arr, 0, arr.size()-1);
    }
};