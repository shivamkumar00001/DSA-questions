class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         
         queue<pair<int,int>>q;
         int count =0;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2)q.push({i,j});
                if(grid[i][j] == 1)count++;
            }
         }
         
         int total =0;
         int ans=0;
         while(q.size()>0){
             int s = q.size();
             for(int i=0;i<s;i++){
                 
                 auto [a,b] = q.front();
                 q.pop();
                 if(a+1<grid.size() && grid[a+1][b] ==1){
                    grid[a+1][b] =2;
                    q.push({a+1,b});
                    total++;
                 }
                 if(a-1>=0 && grid[a-1][b] ==1){
                    grid[a-1][b] =2;
                    q.push({a-1,b});
                    total++;
                 }
                 if(b+1<grid[0].size() && grid[a][b+1] ==1){
                    grid[a][b+1] =2;
                    q.push({a,b+1});
                    total++;
                 }
                 if(b-1>=0 && grid[a][b-1] ==1){
                    grid[a][b-1] =2;
                    q.push({a,b-1});
                    total++;
                 }
             }
             ans++;
         }
         if(count == 0 && total ==0) return 0;
         if(count == total) return ans-1;
         return -1;
    }
};