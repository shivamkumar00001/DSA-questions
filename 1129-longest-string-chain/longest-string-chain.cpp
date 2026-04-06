class Solution {
public:
    
    bool isPossible(string &a, string &b){
        
        if(b.size() != a.size() + 1) return false;

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            } else {
                j++; 
            }
        }

        return i == a.size();
    }

    int longestStrChain(vector<string>& words) {
        
        int n = words.size();

        // Step 1: sort by length
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        // Step 2: DP
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPossible(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};