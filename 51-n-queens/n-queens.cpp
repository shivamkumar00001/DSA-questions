class Solution {
public:
    vector<vector<string>> ans;

    void helper(int & n, vector<string> &v,int ind){

        if( ind == n){
            ans.push_back(v);
            return ;
        }

        for(int i=0;i<n;i++){
            int x=i-1;
            int y=ind-1;
            bool flag = false;
            while(x>=0 && y>=0 ){
                if(v[y][x] =='Q'){
                flag =true;
                break;
                }
                x--;
                y--;
            }
            
            if(flag == true) continue;
            x = i;
            y = ind-1;
            while(y>= 0){
                if(v[y][x] =='Q'){
                flag =true;
                break;
                }
                y--;
            }

            if(flag == true) continue;
            x = i+1;
            y = ind-1;
            while(y>=0 && x<n){
                if(v[y][x] =='Q'){
                flag =true;
                break;
                }
                x++;
                y--;
            }
            if(flag == true) continue;
            
                v[ind][i] = 'Q';
                helper(n,v,ind+1);
                v[ind][i] = '.';

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v;
        
        for(int i =0 ;i<n;i++){
            string s;
            for(int j=0;j<n;j++){
            
                s.push_back('.');  
            }
            v.push_back(s);
    
        }

        helper(n,v,0);
        return ans;
    }
};