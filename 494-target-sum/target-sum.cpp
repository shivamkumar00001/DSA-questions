class Solution {
public:
    void helper( vector<int>& nums, int & target, int ind,int val, int& count){

        if(ind == nums.size() && val ==target){
            count++;
            return;
        }
        if(ind == nums.size()) return;

        helper(nums,target, ind+1, val+nums[ind], count);

        helper(nums, target, ind+1, val-nums[ind], count);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count =0;
        helper(nums,target, 0,0,count);
        return count;
    }
};