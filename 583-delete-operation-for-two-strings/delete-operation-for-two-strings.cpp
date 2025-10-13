class Solution {
public:
    vector<vector<int>>dp;
    int helper( string &word1 , string & word2, int i, int j){

        if(i == word1.size() || j == word2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j] =  1+helper(word1, word2, i+1,j+1);
        }
        else{
            return dp[i][j] = max(helper(word1, word2,i+1,j), helper(word1, word2, i, j+1));
        }
    }
    int minDistance(string word1, string word2) {
        
        dp.resize(word1.size()+1, vector<int>(word2.size()+1,-1));

        int val = helper(word1, word2, 0,0);

        int size = max (word1.size(),word2.size());

        int ans  = 0;
        ans = word1.size()-val;
        ans = ans + word2.size()-val;
        return ans;
        
    }
};