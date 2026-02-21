class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int p=0;
        int n=1;
        int s = nums.size();
        vector<int> result(s,0);
        int i =0;
        while(i<s){
           
            if( nums[i]>=0){
                result[p] = nums[i];
                p+=2;
            }

            else if( nums[i]<0){
                result[n] = nums[i];
                n+=2;
            }
            i++;
        }

        while(p<s){
            result[p] = nums[p];
            p+=2;
        }
        while(n<s){
            result[n] = nums[n];
            n+=2;
        }
        return result;
    }
};












