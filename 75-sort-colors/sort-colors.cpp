class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int cr =0;
        int cw =0;
       

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) cr ++;
            else if (nums[i] ==1) cw ++;
        }

        int i =0;
        int j = cr;
        int k = cw;
        for(int i=0;i<nums.size();i++){
            if(i<j) nums[i] =0;
            else if(i>=j && i< j+k) nums[i] = 1;
            else if(i>=j+k) nums[i] = 2;
        }
    }
};