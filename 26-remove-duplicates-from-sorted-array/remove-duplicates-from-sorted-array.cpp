class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
            int l = 1;
            int r = 1;
            int k = 1;
            int s = nums.size();
            while(r<s){

                if(nums[r] == nums[r-1]){
                    r++;
                    continue;
                }
                else if(nums[r] != nums[r-1]){
                    nums[l] = nums[r];
                    l++;
                    r++;
                    k++;
                }
            }

            return k;

    }
};
















