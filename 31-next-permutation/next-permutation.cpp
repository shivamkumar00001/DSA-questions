class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int p =-1;
      
      for(int i=0;i<n-1;i++){
        if(nums[i]<nums[i+1]){
            p=i;
        }
      }

        if (p >= 0) {
            int j = n - 1;
            while (j > p && nums[j] <= nums[p]) {
                j--;
            }
            swap(nums[p], nums[j]);
        }
        
        reverse(nums.begin() + p +1, nums.end());
    }
};