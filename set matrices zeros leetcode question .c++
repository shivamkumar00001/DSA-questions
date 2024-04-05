class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        set<int> row;
        set<int> column;
        set<int>::iterator itr;


         for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    column.insert(j);
                }
            }
         }   

         for(itr=row.begin();itr!=row.end();itr++){
            int r=*itr;
            for(int j=0;j<matrix[r].size();j++){
                matrix[r][j]=0;
            }
         }

           for(itr=column.begin();itr!=column.end();itr++){
            int c=*itr;
            for(int j=0;j<matrix.size();j++){
                matrix[j][c]=0;
            }
         }
     

    }
};
