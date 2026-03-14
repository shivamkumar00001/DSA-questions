class Solution {
public:
    vector<vector<int>>dp;

    int helper( int m, int n, int i, int j){

        if( i == m && j==n) return 1;

        if(i > m ) return 0;

        if( j>n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = helper( m, n, i+1,j) + helper(m,n,i,j+1);

    }
    int uniquePaths(int m, int n) {
         
         dp.resize(m+5, vector<int>(n+5, -1));

         return helper( m,n,1,1);
    }
};