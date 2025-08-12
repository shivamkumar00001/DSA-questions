class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        priority_queue<double>pq;
        double sum=0;
        for(auto x: nums){
            pq.push(x);
            sum+=x;
        }
        double currSum = sum;
        int count =0;
        while(currSum>sum/2.0){
            double x = pq.top();
            pq.pop();
            x = x/2.0;
            currSum-= x;
            pq.push(x);
            count++;
        }
        return count;
    }
};