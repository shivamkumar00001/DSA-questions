class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
          
          int l=1;
          long long r=0;
          int n= w.size();

          for(int i=0;i<n;i++){
            r=r+w[i];
          }
          long long  max = *max_element(w.begin(), w.end()); 
          l=max;
          long long mid;
          int count;
          int res;
          int ans=-1;

          if(days==1){
            return r;
          }

           while(l<=r){
                mid=l+(r-l)/2;
                res=0;
                count=0;
                for(int i=0;i<n;i++){
                    if(res<mid){
                        res+=w[i];
                    }
                    if(res==mid){
                        count++;
                        res=0;
                    }
                    else if (res>mid){
                        count++;
                        res=w[i];
                    }
                }
               if(res!=0){
                count++;}
                if(count<=days){
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
