vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
     long long n=(a.size()+b.size());
     vector<int> c(n);
      
    for(long long  i=0;i<a.size();i++){
         c[a[i]%n]=a[i];

         
    }
     for(int i=0;i<b.size();i++){
         
         c[b[i]%n]=b[i];
    }
   
   vector<int>d;

   for(long long i=0;i<c.size();i++){
       if(c[i]!=0){
           d.push_back(c[i]);
       }
   }

    return d;

}
