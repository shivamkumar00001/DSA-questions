class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        for(auto x : tasks){
            mp[x]++;
        }
        for(auto x: mp){
            pq.push(x.second);
        }
        int time =0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(pq.size()>0){
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
                }
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]>0)pq.push(temp[i]);
            }

            if(pq.size()>0) time+=(n+1);
            else time += temp.size();
        }

        return time;
    }
};