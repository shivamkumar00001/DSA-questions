class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<double>pq;

        for(auto x : piles){
            pq.push(x);
        }

        while(k>0){
            double x = pq.top();
            pq.pop();
            x = x - floor(x/2.0);
            pq.push(x);
            k--;
        }
        int sum =0;
        while(pq.size()>0){
            double x = pq.top();
            sum+=x;
            pq.pop();
        }
        return sum;
    }
};