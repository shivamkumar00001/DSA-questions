class Solution {
public:
    vector<int> dp;
    int f( int n){

        if(n ==0 || n== 1) return 1;
        if(dp[n] != -1) return dp[n];
        int sum =0;
        for(int k =1;k<=n ;k++){
            sum+= f(k-1)* f(n-k);
        }
        return dp[n] = sum;
    }
    int numTrees(int n) {
      dp.resize(n+1,-1);
      return  f( n );
    }
};