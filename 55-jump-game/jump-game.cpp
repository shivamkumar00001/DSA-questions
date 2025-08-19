class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxi = nums[0];
        int n = nums.size();
        if(n==1) return true;
        for(int i=0;i<n;i++){
            if(nums[i] == 0 && maxi <=i){
                return false;
            }
            maxi = max( maxi, i+nums[i]);
            if(maxi>= n-1) return true;
        }

        return true;
    }
};