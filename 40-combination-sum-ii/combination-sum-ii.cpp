class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& c, int t, int start,vector<int> res){
        if(t == 0) {
            ans.push_back(res);
            return;
        }
        if(t<0) return ;

        for(int i = start; i < c.size();i++){
            // if(t-c[i]<0) continue;
            if(i>start && c[i] == c[i-1]) continue;
            res.push_back(c[i]);
            helper(c, t-c[i], i+1,res);
            res.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {       sort(candidates.begin(),candidates.end());
        vector<int> res;
        helper(candidates, target,0, res);
        return ans;
    }
};