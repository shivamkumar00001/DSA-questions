class Solution {
public:
    string strWithout3a3b(int a, int b) {
        
        string s = "";
        while(a>0 || b>0){
          if(s.size()>=2 && (s[s.size()-1]==s[s.size()-2])){
            if(s.back() == 'b'){
                s+='a';
                a--;
            }
            else{
                s+='b';
                b--;
            }
          }
          else{
            if(a>b){
                s+='a';
                a--;
            }
            else{
                s+='b';
                b--;
            }
          }
        }
        return s;
        
    }
};