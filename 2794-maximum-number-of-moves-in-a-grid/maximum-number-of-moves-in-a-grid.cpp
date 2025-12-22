class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if( i>=n || j>=m) return 0;

        int countu =0;
        int counth =0;
        int countd =0;
        int ans = INT_MIN;

        if(dp[i][j]!=-1) return dp[i][j];

        if(j+1<m && i>0 && grid[i][j] < grid[i-1][j+1] ){
            countu = helper(grid, i-1 ,j+1)+1;
        }
        if(j+1<m && grid[i][j]< grid[i][j+1]){
            counth = helper(grid, i, j+1)+1;
        }
        if(j+1<m && i+1<n && grid[i][j] < grid[i+1][j+1]){
            countd = helper(grid, i+1,j+1)+1;
        }

        ans = max({ans,countu,counth,countd});
        return dp[i][j] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        
        dp.resize(grid.size(), vector<int>(grid[0].size(),-1));
        int ans =INT_MIN;
        for(int i=0;i<grid.size();i++){
            ans = max(ans,helper(grid,i,0));
        }
        return ans;
    }
};