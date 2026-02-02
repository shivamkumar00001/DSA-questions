class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>qu;
        int count=0;
        int r =0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j =0; j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                }
                else if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        qu.push({-1,-1});
        
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int mins =0;
        while(qu.size()>0){
            auto cell = qu.front();
            int x= cell.first;
            int y= cell.second;
            qu.pop();
            if(cell.first == -1 && cell.second ==-1){
               mins++;
               if(not qu.empty()){
                qu.push({-1,-1});
               }
               else{
                break;
               }
            }

            else{
                for(int i = 0 ; i< 4 ; i++){
                    int a = x+dir[i][0];
                    int b = y+dir[i][1];

                     if(a >= 0 && b >= 0 && a < n && b < m &&
                       grid[a][b] == 1){
                        grid[a][b] = 2;
                        r+=1;
                        qu.push({a,b});
                    }
                }
            }
        }

        if(r==count) return mins-1;
        return -1;
    }
};