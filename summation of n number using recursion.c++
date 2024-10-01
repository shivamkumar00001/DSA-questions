
#include <iostream>

using namespace std;

int rec(int sum, int n ){
   
   if(n<1){
       return sum;
   }
    sum = sum + n;
   rec(sum,n-1);
   
   
  
}
int main()
{
    int sum=rec (0,5);
    cout<<sum;
}
