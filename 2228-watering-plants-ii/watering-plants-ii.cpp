class Solution {
public:
    int minimumRefill(vector<int>& nums, int a, int b) {
        
       int l =0 ;
       int r =nums.size()-1;
       int x = a;
       int y = b;
       int count =0;
        while(l<=r){
            if( l!=r){
                if(x>=nums[l]){
                    x = x-nums[l];
                }
                else{
                    count++;
                    x = a;
                    x = x-nums[l];

                }
                if(y >= nums[r]){
                    y = y-nums[r];
                }
                else{
                    count++;
                    y =b;
                    y = y-nums[r];

                }
            }
            else{
                if(x>=y){
                    if(x>=nums[l]){
                        x = x- nums[l];
                    }
                    else{
                        count++ ;
                        x = x-nums[l];
                    }
                }
                else{
                    if(y>=nums[r]){
                        y = y- nums[l];
                    }
                    else {
                        count++;
                        y = y-nums[r];
                    }
                }
            }
            l++;
            r--;
        }

        return count ;
    }
};