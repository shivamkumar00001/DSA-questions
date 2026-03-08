class Solution {
public:
    unordered_map<char, string>mp;
    vector<string> ans;

    void helper( string digits, int index, string temp){

        if(index == digits.size()){
            cout<<temp;
            ans.push_back(temp);
        }
            string s = mp[digits[index]];
            for(int j = 0 ; j< s.size() ; j++){
                helper(digits, index+1, temp+s[j]);
            }
    }
    vector<string> letterCombinations(string digits) {


        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        helper(digits, 0, temp);
        return ans;
    }
};