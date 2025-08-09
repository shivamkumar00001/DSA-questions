class Solution {
public:
    typedef pair<int,int> p;
    long long findScore(vector<int>& nums) {
        priority_queue<p, vector<p>, greater<p> >pq;
        long long n = nums.size();
        if (n==1) return nums[0];
        long long  score =0;
        for(long long i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(pq.size()>0){
            auto x = pq.top();
            pq.pop();
            if(nums[x.second]==-1) continue;
            else{
                if(x.second == 0) {
                    nums[x.second] =-1;
                    nums[x.second+1] = -1;
                }
                else if(x.second == n-1){
                    nums[x.second] = -1;
                    nums[x.second-1] =-1;
                }
                else {
                    nums[x.second-1] = -1;
                    nums[x.second] = -1;
                    nums[x.second+1] = -1;
                }
                score+= x.first;
            }
        }
        return score;
    }
};