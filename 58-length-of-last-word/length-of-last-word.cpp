class Solution {
public:
    int lengthOfLastWord(string s) {
        
        bool flag = false;
        int ans =0;
        int n = s.size();
         for(int i = n-1;i>=0;i--){
            if(s[i] != ' '){
                flag = true;
                ans ++;
            }
            else if( s[i] == ' ' && flag) break;
         }
         return ans;
    }
};