#include<bits/stdc++.h>

using namespace std;

int main(){

 int n;
    cin>>n;

    vector<int> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }


for(int i=0;i<n;i++){
    int min=i;
    for(int j=i;j<n;j++){
         if(a[j]<a[min]){
            swap(a[j],a[min]);
         }         
    }
}



for(int i=0;i<n;i++){
    cout<<a[i];
}
    
  
    }




     


