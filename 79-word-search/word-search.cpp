class Solution {
public:
    vector<vector<int>> d = {{1,0},{0,1},{-1,0},{0,-1}};

    bool helper( vector<vector<char>>& board, int i, int j, string& word, int x){

        if(x == word.size()) return true;
        if(i<0 || i>= board.size() || j<0 || j>= board[0].size() || board[i][j]!=word[x]) return false;
                char temp = board[i][j];
                board[i][j] ='*';

        for(int y = 0 ;y<4;y++){
            int a = i+d[y][0];
            int b = j+d[y][1];

                if(helper(board, a,b,word,x+1)) return true;
      
        }
                board[i][j] =temp;

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {   
          for(int i =0 ;i<board.size();i++){
            for(int j =0 ;j<board[0].size();j++){
                if(word[0] == board[i][j]){
                    if(helper(board,i,j,word,0))return true;
                }
            }
          }

          return false;
    }
};