class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sign = 0;
        int lidx = nums[0];
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2){
            if(nums[0]!=nums[1]) return 2;
            else return 1;
        }
        int count =1;
        for(int i = 1;i<n;i++){
            if(sign == 0){
                if(nums[i]-lidx>0){
                    count++;
                    sign =-1;
                }
                else if (nums[i]-lidx<0){
                    count++;
                    sign = 1;
                }
                
                
            }
            else if(sign == -1){
                if(nums[i]-lidx<0){
                    count++;
                    sign =1;
                    
                }
            }
            else if(sign == 1){
                if(nums[i]-lidx>0){
                    count++;
                    sign =-1;
                    
                }
            }
            lidx=nums[i];
        }

        return count;
    }
};