class Solution {
public:
    
    vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid, int i, int j){
       int n = grid.size();
       int m = grid[0].size();
       if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return;

        grid[i][j] = 0;
        for(int d = 0 ; d< 4; d++){
            int x = i + dir[d][0];
            int y = j + dir[d][1];
                dfs(grid , x ,y);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        

        int count =0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0 ;i<n ;i++){
           if(grid[i][0] ==1) dfs(grid, i,0);
           if(grid[i][m-1] == 1) dfs(grid, i,m-1);
        }

        for(int i =0 ;i<m; i++){
            if(grid[0][i] == 1) dfs(grid,0,i);
            if(grid[n-1][i] == 1) dfs(grid, n-1, i);
        }
        for(int i =0; i<n ; i++){
            for(int j =0 ; j<m ; j++){
              if(grid[i][j] == 1){
                count++;
              }
            }
        }

        return count;
    }
};