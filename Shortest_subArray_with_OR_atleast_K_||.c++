class Solution {


void updateFreq (vector<int>& buffer , int v , int value){
        for(int i=0;i<32;i++){
            if(v & (1<<i)){
                buffer[i]+=value;
            }
        }
    }

    int getNumber (vector<int>& buffer){
        int number =0;
        long long  pow = 1;
        for(int i=0;i<32;i++){
           if(buffer[i]>0){
            number +=pow;
            }
            pow*=2;
        }
        return number;
    }


public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
           if(k==0) return 1;

           int n=nums.size();
           int countOr=0;
           int siz= INT_MAX;

           vector<int> buffer(32,0);
           
           int l=0;
           int r=0;

           while( r<n){
                
                updateFreq(buffer , nums[r], 1);
                countOr |= nums[r];
                while(l<=r and countOr>=k){
                    siz = min(siz,(r-l+1));
                    updateFreq(buffer,nums[l],-1);
                    countOr=getNumber(buffer);
                    l++;
                }
                r++;
           }

           if(siz != INT_MAX) return siz;

           return -1;
           
    }
};
