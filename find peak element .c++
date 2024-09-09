class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
         int l=0;
         int r=nums.size()-1;

         int mid=0;
         if(nums.size()>1){
         while(l<=r){

            mid=(l+r)/2;

            if( mid>0 && mid < nums.size()-1 && nums.size()>2 && nums[mid]>nums[mid-1]&&nums[mid]<nums[mid+1]){
               
                l=mid+1;

            }
            else if( mid>0 && mid < nums.size()-1 && nums.size()>2 && nums[mid]<nums[mid-1]&&nums[mid]>nums[mid+1]){
               
                r=mid-1;

            }
            else if( mid>0 && mid < nums.size()-1 && nums.size()>2 && nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1]){
               
                r=mid-1;

            }
            
          
            else if(mid>0 && mid < nums.size()-1 && nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
                
                return mid;

            }

            else if(mid==0){
                        if(nums[mid]>nums[mid+1]){
                            return 0;
                        }
                        else { 
                            return 1;
                        }
            }

            else if(mid == nums.size()-1){
              
                    return mid;
                }
        
            
                
         }
    }
         return 0;

    }
};
