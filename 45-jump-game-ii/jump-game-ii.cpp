class Solution {
public:
    int jump(vector<int>& nums) {
          int nextInd= nums[0];
          int maxi = nums[0];
          int count=1;
          if(nums.size()==1) return 0;
          for(int i=0;i<nums.size()-1;i++){
             
             if(nums[i] == 0 && maxi<=i) return 0;

             if(i<nextInd){
                maxi = max(maxi,i+nums[i]);
             }
             else if(i==nextInd){
                maxi = max(maxi,i+nums[i]);
                nextInd = maxi;
                count++;
             }
          }
          return count;
    }
};