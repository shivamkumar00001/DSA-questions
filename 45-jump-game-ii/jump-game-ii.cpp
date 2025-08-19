class Solution {
public:
    int jump(vector<int>& nums) {
        int count =0;
        int n = nums.size();
        if(n==1) return 0;
        int range = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max (maxi,i+nums[i]);
            if(i == range){
                count++;
                range = maxi;
                if(range >= n-1) return count;
            } 
        }
        return count;
    }
};