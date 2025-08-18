class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        int m =0;
        for(int i=0;i<nums.size();i++){
          m = max(nums[i],m);
        }
       
        return ((m+k)*(m+k-1))/2 - (m*(m-1))/2;
    }
};