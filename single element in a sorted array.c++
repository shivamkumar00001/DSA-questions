class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
               
          int l=0;
          int r=nums.size()-1;

          int mid=0;
        if(nums.size()>2){
          while(l<=r){
            mid=(l+r)/2;
            if(mid%2==0){
                if( mid>0 && nums[mid]==nums[mid-1]){
                    r=mid-1;
                }
                else if(nums[mid]==nums[mid+1]){
                    l=mid+1;
                }
                else{
                    return nums[mid];
                }
            }
             if(mid%2!=0){
                if(nums[mid]==nums[mid-1]){
                    l=mid+1;
                }
                else if(mid<nums.size()-1&&nums[mid]==nums[mid+1]){
                    r=mid-1;
                }
                else{
                    return nums[mid];
                }
            }
          }
        }     
        else {
            return nums[0];
        }
        return 0;

    }
};
