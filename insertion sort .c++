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
        int j=i-1;
        int key=a[i];
        while(j>=0&& a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
   



for(int i=0;i<n;i++){
    cout<<a[i];
}
    
  
    }




     


