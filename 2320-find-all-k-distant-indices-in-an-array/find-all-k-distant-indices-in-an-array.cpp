class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) { 
        
        vector<int> ans;
        int i=0;
        int n =nums.size();

        while(i<n){
            if(nums[i] == key){
                int x =i+k;
                while(i<=x ){
 
                    if(nums[i] !=key) nums[i] = -1;
                    else x = i+k;
                    i++;
                    if(i==n) break;
                }
            }
            else i++;
        }
        i =n-1;
        while(i>=0){
            if(nums[i] == key){
                int x = i-k;
                while( i>=x){
                    if(nums[i] != key) nums[i] =-1;
                    else x = i-k;
                    i--;
                    if(i<0) break;
                }
            }
            else i--;
        }
        
        for(int j=0;j<n;j++){
            if(nums[j] ==-1 || nums[j] == key){
                ans.push_back(j);
            }
        }
        return ans;
    }
};