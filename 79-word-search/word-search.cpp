class Solution {
public:
    vector<vector<int>> d = {{1,0},{0,1},{-1,0},{0,-1}};

    bool helper( vector<vector<char>>& board, int i, int j, string& word, int x,vector<vector<int>>&visited){

        if(x == word.size()) return true;
        if(i<0 || i>= board.size() || j<0 || j>= board[0].size() || board[i][j]!=word[x]) return false;
       
        for(int y = 0 ;y<4;y++){
            int a = i+d[y][0];
            int b = j+d[y][1];
            if(visited[i][j] == 0){
                visited[i][j] =1;
                if(helper(board, a,b,word,x+1,visited)) return true;
                visited[i][j] =0;
            }
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
         vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));          
          for(int i =0 ;i<board.size();i++){
            for(int j =0 ;j<board[0].size();j++){
                if(word[0] == board[i][j]){
                    if(helper(board,i,j,word,0,visited))return true;
                }
            }
          }

          return false;
    }
};