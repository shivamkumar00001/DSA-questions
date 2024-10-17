class Solution {
public:

    void combinations(int ind, vector<vector<int>> & ans, vector<int> &ds, vector<int> & nums){

        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        combinations(ind+1,ans,ds,nums);
        ds.pop_back();
        combinations(ind+1,ans,ds,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
           
        vector<vector<int>> ans;
        vector<int> ds;

        combinations(0,ans,ds,nums)   ;
        return ans;
    }
};
