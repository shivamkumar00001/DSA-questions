class Solution {
public:
    
// recursion + memoization

    // int  helper(int m, int n , int i, int j,vector<vector<int>> &dp){
    //     if(i == m-1 && j == n-1) {
    //         return 1;
    //     }
    //     if(dp[i][j]!= -1) return dp[i][j];

    //     return dp[i][j] = ((i<m-1)?helper(m,n,i+1,j,dp):0)+
    //     ((j<n-1)?helper(m,n,i,j+1,dp):0);
        
    // }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        // return helper(m , n , 0 , 0,dp);

        if(m== 1 || n == 1) return 1;

        for(int i = 1 ;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};