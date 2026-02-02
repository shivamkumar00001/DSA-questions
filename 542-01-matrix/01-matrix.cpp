class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<pair<pair<int,int>,int>> q;
        
        int m = mat.size();
        int n = mat[0].size();
        for(int i =0; i<mat.size();i++){
            for(int j = 0; j<n; j++){
              if(mat[i][j] == 0)
                q.push({{i,j},0});
            }
        }
        
        vector<vector<int>>d = {{1,0}, {0,1},{0,-1},{-1,0}};

        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));

        while(q.size()>0){
            auto cell = q.front();
            q.pop();
            int x = cell.first.first;
            int y = cell.first.second;
            int dist = cell.second;
            
            for(int i=0;i<4;i++){
                int a = x+d[i][0];
                int b = y+d[i][1];

                if(a>=0 && b >=0 && a<m && b<n && mat[a][b] == 1){
                    if(ans[a][b] > dist + 1){
                        ans[a][b] = dist + 1;
                        q.push({{a, b}, dist + 1});
                    }
                }
            }
        }
        for(int i =0 ;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j] == INT_MAX)
                ans[i][j] = 0;
            }
        }
        return ans;
    }
};