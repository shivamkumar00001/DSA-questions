class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=0;

        int n= nums.size();

        for(int i=0;i<n;i++){
            r+=nums[i];
        }
        int max=*max_element(nums.begin(),nums.end());
        l=max;

        int mid ;
        int ans=-1;

        if(k>n){
            return ans;
        }
        while(l<=r){

            mid=(l+r)/2;

            int m=0;
            int sum=0;
            for(int i=0;i<n;i++){
                
                sum+=nums[i];
                if(sum>mid){
                    sum=nums[i];
                    m++;
                }
                else if(sum==mid){
                   sum=0;
                    m++;
                }

            }
            if(sum!=0){
                m++;
            }
            if(m<=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

                     
        }
        return ans;
    }
};
