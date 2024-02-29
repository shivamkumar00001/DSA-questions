#include <iostream>
#include<vector>

using namespace std;


int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }
     int k;
     cin>>k;
     int x=nums.size()-k;
      
        for(int i=0;i<nums.size();i++){
            
            cout<<nums[(i+x)%nums.size()];
        }
      
}
