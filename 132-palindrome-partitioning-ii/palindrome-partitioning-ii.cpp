class Solution {
public:
    
    bool isPalindrome( string& s, int i, int j){
         
         while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
         }

         return true;
    }
    vector<int>dp;
    int helper (string& s, int i, int n){
         
         if(i == n) return 0;
         if(dp[i]!=-1) return dp[i];
         int minCost = INT_MAX;
         for(int j=i;j<n;j++){
             
            if(isPalindrome(s, i,j)){
                int ans = 1 + helper(s,j+1,n);
                minCost = min(minCost,ans);
            }
            
         }

         return dp[i] = minCost;
    }
    int minCut(string s) {
         
         int i =0;
         int n = s.size();
         dp.resize(s.size(),-1);
         return helper(s,i,n)-1;
    }
};