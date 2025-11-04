class Solution {
public:
    
    int hamming(string & word1, string &word2){
        int n = word1.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(word1[i]!= word2[i] ){
                count++;
            }
            if(count>1) return count;
        }
        return count;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
         int n = words.size();
        vector<int>prev(n,-1);
        vector<int>dp(n,1);
        int maxval=1;
        int last_idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].size()==words[j].size() && groups[i]!=groups[j] && hamming(words[i],words[j])==1){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        prev[i] =j;
                    }

                    if(dp[i] >maxval){
                        maxval = dp[i];
                        last_idx = i;
                    }
                }
            }
        }

        vector<string>ans;

        while(last_idx!=-1){
            ans.push_back(words[last_idx]);
            last_idx = prev[last_idx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};