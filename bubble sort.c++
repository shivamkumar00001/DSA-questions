#include<bits/stdc++.h>

using namespace std;

int main(){

 int n;
    cin>>n;

    vector<int> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

for(int j=0;j<n;j++){
    for(int i=0;i<n-j;i++){
        if(a[i]>=a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
}
for(int i=0;i<n;i++){
    cout<<a[i];
}
    
  
    }




     


