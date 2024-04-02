class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> v1;
        vector<int> v2;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                v1.push_back(nums[i]);
            } else {
                v2.push_back(nums[i]);
            }
        }
        int x = nums.size();
        nums.clear();

         int j=0;
         int k=0;
        for (int i = 0; i < x; i++) {
           
            if (i % 2 == 0) {
                nums.push_back(v1[j]);
                j++;
            } else if(i%2!=0) {
                nums.push_back(v2[k]);
                k++;
            }
        }

        return nums;
    }
};
