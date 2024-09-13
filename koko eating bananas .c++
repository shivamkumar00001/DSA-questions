class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
          long long int l,r;
          long long int n=piles.size();

        long long  int max = *max_element(piles.begin(), piles.end());

          

           l=1;
           r=max;
          long long int count;
           long long int mid ;
           long long int min;

           while(l<=r){
                mid=((l+r)/2);
                count =0; 
               for(int i=0;i<n;i++){
                   
                   count+=ceil(double(piles[i])/double(mid));

               }

               if(count<=h){
                r=mid-1;
                     
                    
                        min=mid;
                     
               }

               if(count>h){
                l=mid+1;
               }

           }
           
           return min;

    }
};
