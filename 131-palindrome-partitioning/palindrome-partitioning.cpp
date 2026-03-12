class Solution {
public:
    
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;

        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    vector<vector<string>> ans;

    void helper(string s, int ind, vector<string>& temp){
        
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            
            string sub = s.substr(ind, i-ind+1);

            if(isPalindrome(sub)){
                temp.push_back(sub);
                helper(s, i+1, temp);
                temp.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(s, 0, temp);
        return ans;
    }
};