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
     
     for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]==nums[j]){
                nums.erase(nums.begin()+j);
            }
        }
     }

     cout<<nums.size()<<endl;
     for(int i=0;i<nums.size();i++){
        cout<<nums[i];
     }
      
}
