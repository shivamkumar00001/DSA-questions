class Solution {
public:
    vector<vector<int>>dp;
    bool helper( string& s1, string & s2, string& s3, int i, int j){
           int k = i+j;
        if (i == s1.size() && j == s2.size() && k == s3.size())
            return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(s1[i] == s3[k]){
            ans = ans || helper(s1,s2,s3, i+1, j);
        }
        if(s2[j] == s3[k]){
            ans = ans ||  helper(s1,s2,s3,i,j+1) ;
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
        if(s1.size()+s2.size() != s3.size()) return false;

        return helper(s1,s2,s3, 0,0);
    }
};