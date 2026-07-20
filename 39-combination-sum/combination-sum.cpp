class Solution {
public:
    
    vector<vector<int>>ans;
    
    void helper(int sum, vector<int>& arr, int k,int i,vector<int> temp){
        if(sum == k){
            ans.push_back(temp);
            return;
        }
        if(sum>k) return;
        if(i==arr.size()) return;
        
        temp.push_back(arr[i]);
        helper(sum+arr[i], arr,k,i,temp);

        temp.pop_back();
        helper(sum,arr,k,i+1,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        helper(0, candidates,target,0,temp);
        return ans;
    }
};