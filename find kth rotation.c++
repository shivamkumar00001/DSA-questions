class Solution {
  public:
    int findKRotation(vector<int> &arr) {
              int l=0;
              int r=arr.size()-1;
              
              int mid=(l+r)/2;
              
              int max=arr[mid];
              
              int k=mid+1;
              
              int rit = mid-1;
              while(l<=rit){
                  int mid1=(l+rit)/2;
                  
                   if(arr[mid1]>max){
                       max=arr[mid1];
                       k=mid1+1;
                       l=mid1+1;
                   }
                   else{
                       rit=mid1-1;
                   }
                  
              }
              
              int lef=mid+1;
              while(lef<=r){
                  int mid2=(lef+r)/2;
                  
                  if(arr[mid2]>max){
                      max=arr[mid2];
                      k=mid2+1;
                      lef=mid2+1;
                  }
                  else{
                      r=mid2-1;
                  }
              }
              
              int ans=k % arr.size();
              return ans;
    }
};
