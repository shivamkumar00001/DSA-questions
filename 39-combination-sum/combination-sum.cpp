class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& arr,int start, int t,vector<int>res){
        // if(t<0) return;
        if(t==0){
            ans.push_back(res);
            return;
        }
        if(start == arr.size()) return;
        if(arr[start]<= t){
            res.push_back(arr[start]);
            helper(arr, start, t-arr[start], res);
            res.pop_back();
        }
        helper(arr,start+1, t, res);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end()); // enable pruning
        vector<int> res;
        helper(candidates, 0,target, res);
        return ans;
    }
};
