class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        int val =INT_MIN/2;
        for(int i=0; i<nums.size() ;i++){

            int j =i+1;
            int k = nums.size()-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    return target;
                }
                else if (sum < target){
                    if(abs(target - val) >= abs(target -sum)){
                        val =sum;
                    }
                    j++;
                }
                else if(sum > target){
                    if(abs(target - val) >= abs(target -sum)){
                        val = sum;
                    }
                    k--;
                }
            }
        }
        return val;
    }
};