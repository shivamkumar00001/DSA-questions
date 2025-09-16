class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        int val =1;
        int i=0,j=0;
        if(grid[0][0] != 0) return false;
        while(val< n*n){
            if(i>=1 && j>=2 && grid[i-1][j-2] == val){
                i-=1;
                j-=2;
            }
            else if(i>=1 && j+2<n && grid[i-1][j+2] == val){
                i-=1;
                j+=2;
            }
            else if(i+1<n && j>=2 && grid[i+1][j-2] == val){
                i+=1;
                j-=2;
            }
            else if(i+1<n && j+2<n && grid[i+1][j+2] ==val){
                i+=1;
                j+=2;
            }
            else if(i>=2 && j>=1 && grid[i-2][j-1] == val){
                i-=2;
                j-=1;
            }
            else if(i>=2 && j+1<n && grid[i-2][j+1] == val){
                i-=2;
                j+=1;
            }
            else if(i+2<n&& j>=1 && grid[i+2][j-1] == val){
                i+=2 ;
                j-=1;
            }
            else if(i+2<n && j+1<n && grid[i+2][j+1] ==val){
                i+=2;
                j+=1;
            }
            else return false;
            val++;
        }
        return true;
    }
};