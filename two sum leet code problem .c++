class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer{}; 
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j] + nums[i]==target && i != j){
                    answer.push_back(i);
                    answer.push_back(j);
                    goto B;
                }
            }
                if(0)
                B : break;
                
        }
        return answer;
    }
    };
