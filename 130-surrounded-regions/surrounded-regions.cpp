class Solution {
public:
    
    vector<vector<int>> d = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs (vector<vector<char>>& board, int i, int j){
        
        int m = board.size();
        int n = board[0].size();

        if(i<0 || j<0 || i>=m || j>= n || board[i][j]!= 'O') return;

        board[i][j] = '1';
        for(int e =0 ;e<4;e++){
            int x = i+d[e][0];
            int y = j+d[e][1];

            if(x>=0 && y>= 0 && x<=m-1 && y<=n-1 && board[x][y] == 'O'){
                dfs(board, x,y);
            }
        }
        return;

    }
    void solve(vector<vector<char>>& board) {
        

        int m = board.size();
        int n = board[0].size();

        for(int i = 0 ;i<n ;i++){
            if(board[0][i] == 'O')
            dfs(board, 0,i);
        }
        
        for(int i =0 ;i<n ;i++){
            if(board[m-1][i] == 'O')
            dfs(board, m-1,i);
        }
        for(int j=0 ;j<m;j++){
            if(board[j][0] == 'O')
            dfs(board, j,0);
        }
        for(int j =0 ;j<m ;j++){
            if(board[j][n-1] == 'O')
            dfs(board, j, n-1);
        }

        for(int i=0;i<m;i++){
            for(int j =0; j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '1') board [i][j] = 'O';
            }
        }
        return ;
    }
};