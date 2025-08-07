class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({gifts[i],i});
        }
        
        while(k>0){
            auto x = pq.top();
            pq.pop();
            gifts[x.second] = sqrt(x.first);
            pq.push({gifts[x.second],x.second});
            k--;
        }
        long long sum =0;
        for(int i=0;i<n;i++){
            sum+=gifts[i];
        }

        return sum;
    }
};