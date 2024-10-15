class Solution {
public:
    
    void combination(int ind, vector<int>& candidates, vector<vector<int>>& ans,int target , vector<int>& ds ){
            
            if(ind == candidates.size()){
                if(target==0){
                    ans.push_back(ds);
                }
                return;
            }

            if (target>=candidates[ind]){
                ds.push_back(candidates[ind]);
                combination(ind , candidates, ans, target-candidates[ind],ds);
                ds.pop_back();
            }
            combination(ind+1,candidates,ans,target,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          
             vector<int> ds;
             vector<vector<int>> ans;
             combination(0,candidates,ans,target,ds);
             return ans;

    }
};
