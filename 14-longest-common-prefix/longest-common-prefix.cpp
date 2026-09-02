class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
           
           string ans = strs[0];
           for(int i=1;i<strs.size();i++){
               
              int a =0 ;
              int b =0;
              if(ans.size()>strs[i].size())ans = ans.substr(0,strs[i].size());
              while(a<ans.size()&& b<strs[i].size()){
                 if(ans[a] == strs[i][b]){
                    a++;
                    b++;
                 }
                 else ans = strs[i].substr(0,b);
              }
           }
           return ans;
    }
};