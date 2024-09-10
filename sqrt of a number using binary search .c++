long long int floorSqrt(long long int n) {
    // Your code goes here
    
   long long int l=0;
   long long int r=n/2;
    
    long long int mid=0;
    long long int max=0;
    
    if (n==1){
        return 1;
    }
    while (l<=r){
        mid=(l+r)/2;
        
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid>n){
            r=mid-1;
        }
        else {
            l=mid+1;
            if(mid>max){
                max=mid;
            }
        }
    }
    
    return max;
    
    
}
