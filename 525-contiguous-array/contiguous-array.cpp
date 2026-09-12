class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         
        unordered_map<int,int>mp;
        int sum = 0;
        if(nums.size()<=1) return 0;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == 0){
                sum-=1;
                if(mp.find(sum)!= mp.end()){
                    ans = max(ans,i-mp[sum]);
                }
                else mp[sum] = i;
                if(sum ==0){
                    ans = max(ans,i+1);
                }
                
            }
            else {
                sum+=1;
                if(mp.find(sum)!=mp.end()){
                    ans = max(ans,i-mp[sum]);
                }
                else mp[sum] = i;
                if(sum == 0){
                    ans = max(ans,i+1);
                }
                
            }
        }
       return ans;
    }
};