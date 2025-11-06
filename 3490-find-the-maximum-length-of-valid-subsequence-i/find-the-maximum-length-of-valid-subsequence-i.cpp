class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int n = nums.size();

       int evenc =0;
       int oddc=0;
       int alto=0;
       int alte=0;
       bool odd = true;
       bool even =true;
       for(int i =0; i<n;i++){

         if(nums[i]%2==0) evenc++;
         
         if(nums[i]%2==1) oddc++;

         if(odd == true && nums[i]%2 ==1){
            alto++;
            odd=false;
         }
         else if(odd == false && nums[i]%2==0){
            alto++;
            odd =true;
         }

         if(even ==  true && nums[i]%2 ==0){
            alte++;
            even = false;
         }
         else if(even == false && nums[i]%2 ==1){
            alte++;
            even =true;
         }
       }

      

       return max ({oddc,evenc,alte,alto});
    }
};
