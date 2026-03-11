class Solution {
public:
    
    vector<string> ans;

    void helper(string &num , int target, long sum, int ind, string temp, long prev){

        if(ind == num.size()){
            if(sum == target) ans.push_back(temp);
            return;
        }
        
        for(int i = ind; i < num.size(); i++){
                
            if(i > ind && num[ind] == '0') break;

            string s = num.substr(ind, i-ind+1);
            long cur = stol(s);

            if(ind == 0){
                helper(num, target, cur, i+1, s, cur);
            }
            else{
                helper(num, target, sum + cur, i + 1,
                       temp + "+" + s, cur);

                helper(num, target, sum - cur, i + 1,
                       temp + "-" + s, -cur);

                helper(num, target, sum - prev + prev * cur, i + 1,
                       temp + "*" + s, prev * cur);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        
        helper(num, target, 0, 0, "", 0);
        return ans;
    }
};