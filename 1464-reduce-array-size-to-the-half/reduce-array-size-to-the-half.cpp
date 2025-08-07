class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int ,int>mp;
        priority_queue<int>pq;
        int n = arr.size();
        int curr = n;
        for(auto x : arr){
            mp[x]++;
        }
        for(auto x: mp){
            pq.push(x.second);
        }
        int count =0;
        while(pq.size()>0){
            int  x = pq.top();
            pq.pop();
            curr = curr-x;
            count++;
            if(curr<=n/2) break;
        }
        return count;
    }
};