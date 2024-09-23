int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.

       int l=0;
       int r= 0;

       int n=boards.size();

       for(int i=0;i<n;i++){
           r+= boards[i];
       }

       int max=*max_element (boards.begin(),boards.end());

       l=max;
        
        int mid;
        int count;
        int ans=-1;
        if(k>n){
            return ans;
        }
       while(l<=r){
              mid=l+(r-l)/2;

              count=0;
              int  m = 0;

              for(int i=0;i<n;i++){
                  count+=boards[i];
                  if(count>mid){
                      m++;
                      count=boards[i];
                  }
                  else if(count==mid){
                      m++;
                      count=0;
                  }

              }
              if(count!=0){
                  m++;
              }
              if(m<=k){
                  ans=mid;
                  r=mid-1;
              }
              else {
                  l=mid+1;
              }
       }
       return ans;
}
