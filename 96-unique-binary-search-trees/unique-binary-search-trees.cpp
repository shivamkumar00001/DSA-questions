class Solution {
public:
  
    int f( int i, int n){

        if(i>=n) return 1;
      
        long long  sum =0;
        for(int k =i;k<=n ;k++){
            sum+= f(i,k-1)* f(k+1,n);
        }
        return  sum;
    }
    int numTrees(int n) {
      return  f( 1,n );
    }
};