class Solution {
public:
    bool isValid(string s) {
        
        int n = s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i] == '('|| s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else if(st.size()>0 && s[i] == ')' && st.top() == '(') st.pop();
            else if(st.size()>0 && st.top() == '{' && s[i] == '}') st.pop();
            else if(st.size()>0 && st.top() == '[' && s[i] == ']')st.pop();
            else return false;
        }
        return st.size() == 0;
    }
};