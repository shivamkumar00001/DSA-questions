class Solution {
public:
   vector<vector<int>> ans;
    void helper( int & k, int n, vector<int> res, int ind){
        if(res.size() == k && n ==0){
            ans.push_back(res);
            return ;
        }

        // if(res.size() == k) return;

        for(int i=ind;i<=9;i++){
            res.push_back(i);
            helper(k,n-i,res,i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> res;
        helper(k, n, res,1);
        return ans;
    }
};