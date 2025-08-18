class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        int maxi =0;
        for(int i=0;i<nums.size();i++){
          maxi = max(nums[i],maxi);
        }
       
        return ((maxi+k)*(maxi+k-1))/2 - (maxi*(maxi-1))/2;
    }
};