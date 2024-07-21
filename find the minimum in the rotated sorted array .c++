class Solution {
public:
    int findMin(vector<int>& nums) {

     int l=0;
     int r=nums.size()-1;

     int mid=0;
     int min=0;

     
        mid=(l+r)/2;
       
            min=nums[mid];
        
       
        int rit=mid-1;
        int mid1=0; 
        while(l<=rit){
             mid1=(l+rit)/2;
             if(nums[mid1]<min){
                min=nums[mid1];
                rit=mid1-1;
             }
             else{
                l=mid1+1;
             }
        }
        int lef=mid+1;
        while(lef<=r){
           mid1=(lef+r)/2;
            if(nums[mid1]<min){
                min=nums[mid1];
                r=mid1-1;
             }
             else{
                lef=mid1+1;
             }
        }

        return min;

     
    }
};
