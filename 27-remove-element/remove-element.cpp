class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        

        int i=0;
        int j=0;
        int count =0;
        while(j<nums.size()){
            if(nums[j]!=val){
                nums[i] = nums[j];
                i++;
                j++;
                count++;
            }
            else if(nums[j] == val){
                j++;
            }
        }

        return count;
    }
};