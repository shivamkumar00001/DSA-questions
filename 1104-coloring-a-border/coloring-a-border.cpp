class Solution {
public:
    
    vector<pair<int,int>>inner;
    vector<pair<int,int>>border;
    void dfs(vector<vector<int>>& grid, int i, int j, int color,int original){
        
        if(i<0 || j <0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != original) return;
        
        grid[i][j] = -1;
        dfs(grid, i+1,j,color, original);
        dfs(grid, i,j+1,color, original);
        dfs(grid, i-1,j,color, original);
        dfs(grid, i,j-1,color, original);

        if(not(i==0|| j==0 || i == grid.size()-1 || j == grid[0].size()-1 || grid[i+1][j]!=-1 || grid[i-1][j]!= -1 || grid[i][j+1] != -1 || grid[i][j-1] != -1)){
            inner.push_back({i,j});
        }else {
            border.push_back({i,j});
        }

    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        if(grid[row][col] == color) return grid;
        int original = grid[row][col];
        dfs(grid, row, col, color,original);

        for(int i=0 ;i< inner.size(); i++){
            int a = inner[i].first;
            int b = inner[i].second;
            grid[a][b] = original;
        }

        for(int i=0 ; i<border.size(); i++){
            int a= border[i].first;
            int b =border[i].second;

            grid[a][b] = color;
        }
        return grid;
    }
};