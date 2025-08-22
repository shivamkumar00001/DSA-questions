class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        double op =0.0;
        double dec =0.0;
        double inc = 0.0;
        int n = nums1.size();

        for(int i=0;i<n;i++){
            int diff = nums1[i]-nums2[i];
            if(k==0 && diff != 0){
                return -1;
            }
            else if(k==0 && diff ==0) continue;
            
            if(diff>0){
                if(diff%k == 0){
                    dec += (diff/k)*0.5;
                }
                else return -1;
            }

            else if(diff<0){
                if(abs(diff)%k == 0){
                    inc += (abs(diff)/k)*0.5;
                }
                else return -1;
            }
        }
        op = dec+inc;
        if(dec != inc || op-floor(op)!=0){
            return -1;
        }
        return (long long)op;
    }
};