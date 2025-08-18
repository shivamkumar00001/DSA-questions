class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        int maxi =0;
        for(int i=0;i<nums.size();i++){
          maxi = max(nums[i],maxi);
        }
        int ans =0;
        while(k--){
           ans+=maxi;
           maxi++;
        }
        return ans;
    }
};