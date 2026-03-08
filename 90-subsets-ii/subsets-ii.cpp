class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int index, vector<int> res){
            ans.push_back(res);
        for( int i = index ; i<nums.size() ;i++ ){
            
            if(i>index && nums[i] == nums[i-1]) continue;
            res.push_back(nums[i]);
            helper(nums, i+1, res);
            res.pop_back();
        }
         
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        helper(nums, 0, res);
        return ans;
    }
};