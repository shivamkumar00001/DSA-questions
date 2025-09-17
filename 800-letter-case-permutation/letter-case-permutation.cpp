class Solution {
public:
     vector<string> ans;
    void helper(string & s, int ind){
        if(ind == s.size()){
            ans.push_back(s);
            return;
        }
        if(isdigit(s[ind])){
            helper(s, ind+1);
        }
        else{
            s[ind] = toupper(s[ind]);
            helper(s, ind+1);
            s[ind] = tolower(s[ind]);

            s[ind] = tolower(s[ind]);
            helper(s,ind+1);
            s[ind] = toupper(s[ind]);
        }
    }
    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return ans;
    }
};