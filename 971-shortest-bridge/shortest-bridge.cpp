class Solution {
public:

    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    void dfs(vector<vector<int>>& grid , int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j< 0 || i>=m || j>=n) return;
        grid[i][j] =-1;
        for(int d =0 ;d< 4;d++){
            int x= i+ dirs[d][0];
            int y = j+ dirs[d][1];

            if(x>=0 && y>=0 && x<m && y<n && grid[x][y] == 1){
                dfs(grid, x,y);
            }
        }
        return ;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        queue<tuple<int,int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        int mini = INT_MAX;
        int found =0;
        for(int i =0 ;i<m ; i++){
            if(found == 1) break;
            for(int j =0; j<n ;j++){
                if(found ==1) break;
                if(grid[i][j] == 1){
                    dfs(grid, i,j);
                    found =1;
                    break;
                }
            }
        }
        for(int i =0 ;i<m ;i++){
            for(int j =0 ; j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<< endl;
        }
        for(int i =0 ;i<m ;i++){
            for(int j =0 ;j<n;j++){
                if(grid[i][j] == -1){
                    q.push({i,j,0});
                }
            }
        }
        
        while(q.size()>0){
            int s = q.size();
            for(int i =0 ;i< s ;i++){
                auto [x,y,z] = q.front();
                q.pop();
                for(int i =0 ;i<4;i++){
                    int a = x+ dirs[i][0];
                    int b = y+ dirs[i][1];
                    if(a>=0 && b>=0 && a<m && b<n && grid[a][b] == 1){
                        return z;
                    }
                    else if(a>=0 && b>=0 && a<m && b<n && grid[a][b] == 0){
                        grid[a][b] =-1;
                        q.push({a,b,z+1});
                    }
                }
            }
        }
        return mini;
    }
};