class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
           
           int m = mat.size();
           int n = mat[0].size();
           
            vector<vector<int>> v(m, vector<int>(n, 0));

           for(int i=0;i<m;i++){
               
               if(i%2==1){
                  for(int j = 0 ;j<n ;j++){
                      v[i][(j+k)%n] = mat[i][j];
                  }
               }
               else {
                   for(int j = 0 ;j<n ;j++){
                      v[i][j] = mat[i][(j+k)%n];
                  }
               }
           }

           return v == mat;
    }
};