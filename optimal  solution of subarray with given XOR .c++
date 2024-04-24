
 #include <bits/stdc++.h>
int Solution::solve(vector<int> &a, int b) {

     long long count=0;
     int xr=0;
      map<int,int> mpp;
      mpp[xr]++;
     for(int i=0;i<a.size();i++){
         
         xr=a[i]^xr;
         
         int x= xr^b;
         count+=mpp[x];
         
         mpp[xr]++;
         
     }
    
    
    
     return count;
     
     


}
