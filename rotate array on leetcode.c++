class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int x= (nums.size()-k);
       
        vector<int> num;
      if(x>0){
        for(int i=0;i<nums.size();i++){
            
            num.push_back(nums[(i+x)%nums.size()]);
        }
      }
      else{
          x=nums.size()+x;
           for(int i=0;i<nums.size();i++){
            
            num.push_back(nums[(i+x)%nums.size()]);
        }
      }
        nums.clear();
         for(int i=0;i<num.size();i++){
               nums.push_back(num[i]);
         }
        
    }
};
