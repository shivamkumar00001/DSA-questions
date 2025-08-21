class Solution {
public:
    void backtrack(int start, vector<int>& candidates, int target, 
                   vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue; // pruning step

            curr.push_back(candidates[i]);
            backtrack(i, candidates, target - candidates[i], curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end()); // enable pruning
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, candidates, target, curr, ans);
        return ans;
    }
};
