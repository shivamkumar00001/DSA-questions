class Solution {
public:
 vector<vector<int>> vis;
    void dfs(vector<vector<int>>& heights, int i, int j, vector<int>& a){
        if( i < 0 || j < 0 ){
            a[0] = 0;
            return;
        }
        if(i>=heights.size() || j == heights[0].size()){
            a[1] =1;
            return;
        }

        if (vis[i][j]) return;
        vis[i][j] = 1;

        if( i== 0 || heights[i][j]>= heights[i-1][j]){
            dfs(heights, i-1, j,a);
        }
        if( j== 0 || heights[i][j]>= heights[i][j-1]){
            dfs(heights, i, j-1,a);
        }
        if( i== heights.size()-1 || heights[i][j]>= heights[i+1][j]){
            dfs(heights, i+1, j,a);
        }
        if( j== heights[0].size()-1 || heights[i][j]>= heights[i][j+1]){
            dfs(heights, i, j+1,a);
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         vector<vector<int>>result;
         int n = heights.size();
         int m = heights[0].size();
         for(int i = 0 ; i< heights.size(); i++){
            for(int j =0; j< heights[0].size(); j++){
                vis.assign(n, vector<int>(m, 0));
                vector<int>a;
                a.push_back(-1);
                a.push_back(-1);
                dfs(heights, i, j, a);
                if(a[0] == 0 && a[1] == 1){
                    result.push_back({i,j});
                }
            }
         }

         return result;
    }
};