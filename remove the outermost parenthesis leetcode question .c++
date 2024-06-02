class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<int> ss;
        string s;
        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] == '(')
                ss.push(i);
            else
            {
                if(ss.size() == 1)
                {
                    for(int j = ss.top() + 1; j < i; j++)
                        s.pb(S[j]);
                }
                
                ss.pop();
            }
        }
        
        return s;
    }
};
