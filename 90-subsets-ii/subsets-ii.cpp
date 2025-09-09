class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int i, vector<int> res){
        if(i == nums.size()){
            ans.push_back(res);
            return;
        }

       
        if(res.size()==0 ||( nums[i]!= res[res.size()-1])){
            helper(nums,i+1,res);
        }
        res.push_back(nums[i]);
        helper(nums,i+1,res);
        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        helper(nums, 0, res);
        return ans;
    }
};