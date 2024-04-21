#include<vector>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	// Write your code here
int count =0;
int max=0;

for(int i=0;i<arr.size();i++){
	int sum=0;
       count=0;
        for(int j=i;j<arr.size();j++){
		 
		   sum=sum+arr[j];
		  count++;
		     if(sum==0){
			   if(count>max){
		max=count;
	}
		   }

	}
	
}
return max;
}
