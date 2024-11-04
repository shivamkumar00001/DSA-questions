class{
public:
	
	int  count (int i, int arr[],int n, int  sum, int & count1) {
	   //if(i>=n && sum == 0){
	   //      count1 = (count1 + 1) % 1000000007;
	   //    //   cout<<sum<<"-";
	   //     return;
	   // } 
	    if( sum==0 && i==n ){
	       // count1 = (count1 + 1) % 1000000007;
	       return 1;
	        
	    }
	       //   cout<<sum<<"-";
	       //return;
	    
	   
	    if(sum < 0 || i==n  ){
	        
	        return 0;
	    }
	    
	    

	   
	   //   cout<<sum<<"-";
	  return  (count(i+1,arr,n,sum-arr[i],count1) + count(i+1,arr,n,sum,count1))% 1000000007;
	    
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
      
        int count1=0;
          return count(0,arr,n,sum,count1);
         
        
	}

};
