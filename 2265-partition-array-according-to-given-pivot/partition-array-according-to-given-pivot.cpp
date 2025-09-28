class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int less = 0;
        int equal = 0;

        vector<int> ans(nums.size(), 0);

        for(int i =0;i<nums.size();i++){
            if(nums[i]<pivot) less++;
            if(nums[i] == pivot) equal++;
        }
        
        int l = 0;
        int m = less;
        int r = less+equal;
        for(int i= 0 ;i<nums.size();i++){
            if(nums[i]<pivot) {
                ans[l] = nums[i];
                l++;
            }
            else if(nums[i] == pivot){
                ans[m] = nums[i];
                m++;
            }
            else if(nums[i] >pivot){
                ans[r] = nums[i];
                r++;
            }
        }

        return ans;
    }
};