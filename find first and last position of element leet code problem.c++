class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid=0;
        int left=-1;
        int right=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target){
                left=mid;
                right=mid; 
                while(left>=0){

                    if(nums[left]!=target){
                        break;
                    }
                    else{
                        left--;
                    }
                   
                }
                while(right<=nums.size()-1){
                     if(nums[right]!=target){
                      break;
                    }
                    else{
                        right++;
                        }
                }
                left++;
                right--;
                break;
            } 

             else if(target>nums[mid]){
                l=mid+1;
             }     
             else{
                r=mid-1;
             }
        }
        
       
        vector<int> v;
        v.push_back(left);
        v.push_back(right);

        return v;
         
 
    }
};
