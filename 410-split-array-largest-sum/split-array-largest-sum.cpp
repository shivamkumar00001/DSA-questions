class Solution {
public:
    
    int helper(int pages, vector<int> nums){
         int temp=0;
         int count=1;
         for(int i=0;i<nums.size();i++){
            if(temp+nums[i]<=pages){
                temp+=nums[i];
            }
            else {
                count++;
                temp = nums[i];
            }
         }
         return count;
    }
    int splitArray(vector<int>& nums, int k) {
          int low=0;
          long long high =0;
          for(int i =0;i<nums.size();i++){
             high+=nums[i];
             low = max(low,nums[i]);
          }

          int mid = 0;
          int ans =0;
          while(low<=high){
              mid = (low+high)/2;

              int m = helper(mid,nums);

              if(m>k){
                low = mid+1;
              }
              else if(m<=k){
                ans = mid;
                high = mid-1;
              }
              
          }
          return ans;
    }
};