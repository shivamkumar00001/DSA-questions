#include<bits/stdc++.h>

using namespace std;

int main(){

 int m;
    cin>>m;

    vector<int> a(m);
    
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    
  int l=0;
  int r=m;
  int k;
  cin>>k;
  int mid=(l+r)/2;
    while(l<r){

        mid=(l+r)/2;
        if(a[mid]==k){
            cout<<k<<" : found ";
            break;
        }
        if(a[mid]<k){
            l=mid+1;
        }
        if(a[mid]>k){
            l=mid-1;
        }

    }
    
    }




     


