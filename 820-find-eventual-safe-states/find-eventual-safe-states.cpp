class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<vector<int>>v(graph.size());
        vector<int>out(graph.size(),0);
        for(int i =0; i<graph.size();i++){
            out[i] = graph[i].size();

            for(auto a : graph[i]){
                v[a].push_back(i);
            }
        }
        queue<int>q;
        for(int i =0 ;i< graph.size(); i++){
            if(out[i] == 0) q.push(i);
        }
        vector<int>safe;

        while(q.size()>0){
            int curr = q.front();
            q.pop();
            safe.push_back(curr);

            for(auto n : v[curr]){
                 out[n]--;
                 if(out[n] == 0) q.push(n);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};