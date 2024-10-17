class Solution {
public:

    void combinations(int ind, vector<vector<int>> & ans, vector<int> &ds, vector<int> & nums){

        if(ind==nums.size()){
           
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            ans.push_back(ds);
            combinations(i+1,ans,ds,nums);
            ds.pop_back();
            
           
        }
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        combinations(0,ans,ds,nums)   ;
        vector<int>d;

        ans.push_back(d);
        return ans;
    }
};
