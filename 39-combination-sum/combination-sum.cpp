class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& arr,int start, int t,vector<int>res){
        // if(t<0) return;
        if(t==0){
            ans.push_back(res);
            return;
        }
        for(int i=start;i<arr.size();i++){
            if (arr[i] > t) continue;
            res.push_back(arr[i]);
            helper(arr,i,t-arr[i],res);
            res.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end()); // enable pruning
        vector<int> res;
        helper(candidates, 0,target, res);
        return ans;
    }
};
