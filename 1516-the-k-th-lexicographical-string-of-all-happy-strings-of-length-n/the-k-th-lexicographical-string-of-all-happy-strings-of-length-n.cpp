class Solution {
public:
    vector<string> ans;
    void helper( string & s, int n, string & res, int ind){
        if(res.size() == n){
           ans.push_back(res);
            cout<<res<< " ";
            return;
        }
        for(int i=0;i<s.size();i++){
            if(res.size()==0 || res.back()!= s[i]){
                res.push_back(s[i]);
                helper(s, n, res, ind+1);
                res.pop_back();
            }
            else continue;

        }
    }
    string getHappyString(int n, int k) {
        string s = "abc";
        string res = "";
        helper(s, n ,res,0);
        cout<<ans.size();
        if(k-1< ans.size() && k-1>=0){
            return ans[k-1];
        }
        return "";

    }
};