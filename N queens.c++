class Solution {
public:

    void check( int col, vector<vector<string>>&ans, vector<string> &ds, vector<int> & lower, vector<int> &upper, vector<int> &level,int n){

          if(col==n){
            ans.push_back(ds);
            return;
          }

          for(int row=0; row<n;row++){
             if(lower[row+col]==0 && upper[n-1+col-row]==0 && level[row]==0){
                ds[row][col]='Q';
                lower[row+col]=1;
                upper[n-1+col-row]=1;
                level[row]=1;
                check(col+1,ans,ds,lower,upper,level,n);
                ds[row][col]='.';
                lower[row+col]=0;
                upper[n-1+col-row]=0;
                level[row]=0;
             }
          }
    }

    vector<vector<string>> solveNQueens(int n) {
          
          vector<vector<string>> ans;

          vector<string> ds(n);

          string s(n, '.');

          for(int i=0;i<n;i++){
            ds[i]=s;
          }

          vector<int> lower(2*n-1,0);

          vector<int> upper( 2*n-1,0);

          vector<int> level(n,0);

          check (0,ans,ds,lower,upper,level,n);

          return ans;
    }
};
