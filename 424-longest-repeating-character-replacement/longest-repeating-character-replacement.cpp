class Solution {
public:
    int characterReplacement(string s, int k) {
          
          int r=0;
          int l=0;
          int n= s.size();
          map<char,int> m;
          int c=0;
          int value;
          int key;
          int maxlen=0;
          int mf=0;
           while(r<n){
              m[s[r]]++;
              mf=max(mf,m[s[r]]);

              if((r-l+1)-mf>k){
                m[s[l]]--;
                l++;
              }

              maxlen=max(maxlen,r-l+1);
              r++;
           }
              
           return maxlen;
    }
};