class Solution {
public:
    
    vector<vector<int>>dp;
    long long helper( vector<vector<int>>&grid, int i, int j){
         
        if( i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        long long ans1=INT_MAX;
        long long ans2=INT_MAX;
       if(i<grid.size()-1)
        ans1 = helper(grid,i+1,j);
       if(j<grid[0].size()-1)
        ans2 = helper(grid,i,j+1);

        return dp[i][j] = grid[i][j] +min(ans1,ans2); 
    }
    int minPathSum(vector<vector<int>>& grid) {
       dp.resize(grid.size()+5,vector<int>(grid[0].size()+5,-1));
       return  helper( grid , 0,0);
    }
};