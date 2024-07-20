class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        int l=0;
        int r=nums.size()-1;

        int mid=(l+r)/2;

        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target){
                return true;
                break;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return false;

    }
};
