int longestSubarrayWithSumK(vector<int> a, long long k) {
  
    int count=1;
    int sum=0;
    int max=0;

     for(int i=0;i<a.size();i++){
        
         count=1;
         sum=a[i];
         for(int j=i;j<a.size();j++ ){
           if (i != j) {
             sum = sum + a[j];

             count++;
           }
             if(sum==k){
              if(max<count){
             max=count;
         }
              }
              if(sum>k){
                  break;
              }

         }
         
     }
      return max;

}
