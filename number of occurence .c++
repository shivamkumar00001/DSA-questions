	int count(int nums[], int n, int target) {
	    // code here  
	    int l=0;
        int r=n-1;
        int mid=0;
        int left=0;
        int right=0;
        int ans=0;
        
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target){
                left=mid;
                right=mid; 
                while(left>=0){

                    if(nums[left]!=target){
                        break;
                    }
                    else{
                        left--;
                    }
                   
                }
                while(right<=n-1){
                     if(nums[right]!=target){
                      break;
                    }
                    else{
                        right++;
                        }
                }
                left++;
                right--;
                ans=right-left+1;
                
                break;
            } 

             else if(target>nums[mid]){
                l=mid+1;
             }     
             else{
                r=mid-1;
             }
        }
        
        
        return ans;
        
       
	}
};
