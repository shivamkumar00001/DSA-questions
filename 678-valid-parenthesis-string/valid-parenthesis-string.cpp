class Solution {
public:
    bool checkValidString(string s) {
        stack<int> sp;
        stack<int> ss;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i] == '(') sp.push(i);

            else if(s[i] == '*') ss.push(i);

            else{
                if(sp.size()>0) sp.pop();
                else {
                    if(ss.size()>0) ss.pop();
                    else return false;
                }
            }
        }
        while(sp.size()>0 && ss.size()>0){
            if(sp.top()>ss.top()) return false;
            sp.pop();
            ss.pop();
        }
        return sp.empty();
    }
};