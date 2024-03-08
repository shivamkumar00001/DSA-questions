#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> v(2*n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
   
    vector<int> arr(2*v.size());
    vector<int> vi(2*v.size());

    int x=v.size();

    for(int i=(-x);i<x;i++){
        arr[i]=0;
        vi[i]=0;
    }
        
        int ni=0;
        for(int i=0;i<v.size();i++){
            
            arr[v[i]%v.size()]= arr[v[i]%v.size()]+1 ;
            vi[v[i]%v.size()]=v[i];  
        }
        for(int i=(-x);i<x;i++){
            if(arr[i]==1){
                ni=vi[i];
            }
        }
   
          cout<<ni;
}
