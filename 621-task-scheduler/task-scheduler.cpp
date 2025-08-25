class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        int freq =0;
        for(auto x : tasks){
            mp[x]++;
            freq = max (freq,mp[x]);
        }
        int x =0;
        for(auto y: mp){
            if(y.second == freq)
             x++;
        }
        int y = tasks.size();
        return max( (freq - 1)*(n+1) + x, y);

        // first method using priority queue and greedy



        // int time =0;
        // while(!pq.empty()){
        //     vector<int> temp;
        //     for(int i=1;i<=n+1;i++){
        //         if(pq.size()>0){
        //         int freq = pq.top();
        //         pq.pop();
        //         freq--;
        //         temp.push_back(freq);
        //         }
        //     }
        //     for(int i=0;i<temp.size();i++){
        //         if(temp[i]>0)pq.push(temp[i]);
        //     }

        //     if(pq.size()>0) time+=(n+1);
        //     else time += temp.size();
        // }

        // return time;


        // second method using only greedy and math;


    }
};