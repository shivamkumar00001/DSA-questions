class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long>s;
        priority_queue<long long , vector<long long >, greater<long long>>pq;
        pq.push(1);
        long long curr =1;
        s.insert(1);
        for(int count =0;count<n;count++){
            curr = pq.top();
            pq.pop();

            if(s.insert(curr*2).second) pq.push(curr*2);
            if(s.insert(curr*3).second) pq.push(curr*3);
            if(s.insert(curr*5).second) pq.push(curr*5);
        }
        
        return curr;
    }
};