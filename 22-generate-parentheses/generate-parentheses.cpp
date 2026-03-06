class Solution {
public:
    vector<string> ans;
    void helper (int n1, int n2, string s){
        if(n1 ==0 && n2 == 0){
            ans.push_back(s);
            return;
        }
        if(n1>n2) return;

        if(n1>0) helper(n1-1,n2, s+'(');

        if(n2>0 && n1<n2){
            helper(n1,n2-1, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        int n1 = n;
        int n2 = n;
        string s ="";
        helper(n1,n2,s);
        return ans;
    }
};