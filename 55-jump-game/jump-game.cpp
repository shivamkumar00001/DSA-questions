class Solution {
public:
    bool canJump(vector<int>& nums) {
         
         int maxi = nums[0];
         if(nums.size()==1) return true;
         for(int i=0;i<nums.size()-1;i++){
             if(nums[i] == 0 && maxi <=i){
                return false;
            }
            maxi = max(maxi,i+nums[i]);
            if(maxi>=nums.size()-1) return true;
         }
         return false;
    }
};