class Solution {
public:
    
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& grid,int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if( i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        long ans1 = INT_MAX;
        long ans2 = INT_MAX;
        if(i<m-1){
            ans1 = helper(grid,i+1,j);
        }
        if(j<n-1){
            ans2 = helper(grid,i,j+1);
        }

        return dp[i][j] =  grid[i][j]+min(ans1,ans2);

    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(grid, 0,0);

    }
};