class Solution {
public:
   
    vector<vector<int>> dp;

    bool helper(string &s, string &p, int i, int j){
         
        if(i == s.size() && j == p.size()) return true;

        if(j == p.size()) return false;

        // 🔥 Important fix
        if(i == s.size()){
            for(int k = j; k < p.size(); k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = helper(s, p, i+1, j+1);
        }

        if(p[j] == '*'){
            return dp[i][j] = (helper(s, p, i+1, j) || helper(s, p, i, j+1));
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {  
        dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(s, p, 0, 0);
    }
};