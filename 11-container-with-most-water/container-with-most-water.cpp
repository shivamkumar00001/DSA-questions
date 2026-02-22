class Solution {
public:
    int maxArea(vector<int>& nums) {
        

        int l =0;
        int r = nums.size()-1;
        int maxi = INT_MIN;
        while(l<r){
            
            int dist = r-l;
            if(nums[l]<nums[r]){
                maxi = max(maxi, nums[l]*dist);
                l++;
            }
            else{
                maxi = max(maxi, nums[r]*dist);
                r--;
            }
        }

        return maxi;
    }
};