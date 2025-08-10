class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto x : nums){
            pq.push(x);
        }
        long long score = 0;
        for(int i = 0 ;i<k;i++){
            int x = pq.top();
            score += x;
            pq.pop();
            x = ceil(x/3.0);
            pq.push(x);
        }
        return score;
    }
};