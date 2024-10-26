class Solution {
public:
    
    void generate(vector<string> & bracket, string & s, int open , int close){
          if(open==0 && close== 0){
            bracket.push_back(s);
            return;
          }
          if(open>0){
            s.push_back('(');
            generate(bracket,s,open-1,close);
            s.pop_back();
          }
          if(close>0){
            if(open<close){
                s.push_back(')');
                generate(bracket,s,open,close-1);
                s.pop_back();
            }
          }
      

    }
    vector<string> generateParenthesis(int n) {
          
          string s;

          vector<string> bracket;
          
          int open = n;

          int close= n;

          generate(bracket,s,open,close);

          return bracket;
    }
};
