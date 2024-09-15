class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
           
         long long  l,r;
         long long n=b.size();

         long long  max = *max_element(b.begin(), b.end());   
         long long  min = *min_element(b.begin(), b.end()); 
           l=min;
           r=max;
         long long  i;
         long long fool;
         long long count;
         long long  mid ;
         long long  ans=-1; 
         long long an = 1LL * m * k;
           if(an>n){
            return -1;
           }
           while(l<=r){
               
               mid= l + (r-l) / 2;
               count=0;
               fool=0;
               for( i=0;i<n;i++){
                   if(b[i]<=mid){
                    count++;
                   } 
                   else{
                      fool+=(count/k);
                      count=0;
                   }

               }
               fool+=(count/k);

               if(fool>=m){
                ans=mid;
                r=mid-1;
               
               }
               else{
                l=mid+1;
               }
                
           }


         return ans;

    }
};
