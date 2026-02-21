class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        

      int i = 0;
      int j = nums.size()-1;
      int s = j;
      int count =0;

      while(i<=j){
          
          if(nums[i]== val && nums[j] != val){
            swap(nums[i],nums[j]);
            i++;
            j--;
            count++;
          }
          if(nums[i]!=val){
            i++;
            count++;
          }
          if(nums[j] == val){
            j--;
          }
      }

        return count;
    }
};














