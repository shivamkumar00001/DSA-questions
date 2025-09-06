class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        int i =2;
        if(n<3) return 0;
        int prev =0;
        int curr =0;
        int ans =0;
        while(i<n){
    
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                curr = curr+1;
                ans += curr;
            }
            else  {
                curr =0;
            }
                i++;
        }

        return ans ;
    }
};