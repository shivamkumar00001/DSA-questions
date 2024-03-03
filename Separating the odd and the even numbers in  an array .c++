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
     int l=0;
     int r=n-1;
     while(l<r){
       
        if (nums[l]!=1){
            l=l+1;
        }
        if(nums[r]!=0){
            r=r-1;
        }
        if(nums[l]==1&&nums[r]==0){
            int temp=nums[r];
            nums[r]=nums[l];
            nums[l]=temp; 
            l++;
            r++;
        }
     }
     for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
     }
      
}
