class Solution {
public:
    void sortColors(vector<int>& nums) {
     
     int low =0;
     int mid =0;
     int hi = nums.size()-1;

     while(mid<=hi){
        if(nums[mid] == 0){
            swap (nums[low],nums[mid]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1) mid++;
        else if(nums[mid] == 2){
            swap (nums[mid], nums[hi]);
            hi--;
        }
     }
    }
};