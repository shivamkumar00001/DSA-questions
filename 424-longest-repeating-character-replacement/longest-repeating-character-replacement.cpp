class Solution {
public:
    int characterReplacement(string s, int k) {
         
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int n= s.size();
        int mf =0;
        int maxlen =0;
        // int mf =0;
        while(r<n){
            mp[s[r]]++;
            mf = max(mf,mp[s[r]]);
            if((r-l+1)-mf>k){
                
                mp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen,(r-l+1));
            r++;
        }
        return maxlen;
    }
};