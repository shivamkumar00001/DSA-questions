#include<bits/stdc++.h>

using namespace std;

int main(){

 int n;
    cin>>n;

 vector<vector<int>> a(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int countrow=n;
    int countcolumn=n; 

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1&&j<countcolumn){
                countcolumn=j;
                countrow=i;
                break;
            }
        }
    }

    cout<<countrow;
 




    
  
    }




     


