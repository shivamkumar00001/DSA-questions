int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
      int l=0;
      int r=0;
      int ans=-1;
      for(int i=0;i<n;i++){
          r+=arr[i];  
      }
    
    //   int min=*min_element(arr.begin(),arr.end());

      int max=*max_element(arr.begin(),arr.end());
      
      l=max;

      int mid;

      if(m>n){
          return -1;
      }



      while(l<=r){

          mid=l+(r-l)/2;
          int sum=0;
          int k=0;
          for(int i=0;i<n;i++){
              sum+=arr[i];
              if(sum>mid){
                  sum=arr[i];
                  k++;
              }
              else if(sum==mid){
                  sum=0;
                  k++;
              }
          }
          if(sum!=0){
              k++;
          }
          if(k<=m){
              
              ans=mid;
              r=mid-1;
              
          }
          else {
              l=mid+1;
          }


      }

      return ans;

}
