class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
            
              int l=0;
              int r=arr.size()-1;
              int n=arr.size();

              int max=*max_element(arr.begin(),arr.end());
              int count=k;
              int mid;
              if((max-arr.size())>=k){
                   for(int i=1;i<=max;i++){
                          l=0;
                          r=arr.size()-1;
                          count=0;
                           while(l<=r){
                           
                             mid=(l+r)/2;
                           
                             if(arr[mid]==i){
                                count=1;
                                break;
                             }
                           
                             else if(arr[mid]<i){
                                l=mid+1;
                             }
                           
                             else if(arr[mid]>i){
                                r=mid-1;
                             }
                           }
                           if(count==0){
                              k--;
                           }
                           if(k==0){
                            return i;
                           }
                   }
              }

             
                return k+n;
           
             
    }
};
