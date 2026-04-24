class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int count = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        
        vector<pair<int,int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int time = -1;
        int ct =0;
        while(q.size()>0){
             
             int s = q.size();
             time++;
             for(int i=0;i<s;i++){
                 
                 int a = q.front().first;
                 int b = q.front().second;
                 q.pop();
                 
                 for(int d=0;d<dirs.size();d++){
                     int x = dirs[d].first;
                     int y = dirs[d].second;

                     if( a+x<grid.size() && a+x >=0 && b+y>=0 && b+y<grid[0].size() && grid[a+x][b+y] == 1){
                         ct++;
                         grid[a+x][b+y] =2;
                         q.push({a+x,b+y});
                     }
                 }
                 
             }
        }
        if(count ==0) return 0;
        if(ct == count) return time;
        return -1;
 
    }
};