class Solution {
public:

    int helper(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m) return j;

        int dir = grid[i][j];
        int nextcol = j+dir;
        

        if(nextcol<0 || nextcol >=n) return -1;

        if(grid[i][nextcol] != dir ){
            return -1;
        }
        
        return helper(grid, i+1, nextcol);

    }
    vector<int> findBall(vector<vector<int>>& grid) {
        
        vector<int> result(grid[0].size());
        for(int j =0;j<grid[0].size();j++){
            result[j] = helper(grid,0,j);
        }

        return result;
    }
};