class Solution {
public:
    vector<vector<int>>dp;
    int helper(string &text1, string &text2, int i, int j){

        if(i == text1.size()|| j== text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans =0;
        if(text1[i] == text2[j]) ans = 1+helper(text1,text2,i+1,j+1);
        else ans = max(helper(text1,text2,i+1,j),helper(text1,text2,i,j+1));
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1,vector<int>(text2.size()+1,-1));
        return helper(text1, text2, 0,0);

    }
};