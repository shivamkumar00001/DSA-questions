class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         
         queue<int>q;
         vector<int> outdegree(graph.size(),0);
         vector<vector<int>>adj(graph.size());
         for(int i=0;i<graph.size();i++){
            outdegree[i] = graph[i].size();
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
         }

         for(int i=0;i<outdegree.size();i++){
            if(outdegree[i] ==0) q.push(i);
         }
         if(q.size() ==0) return {};
         vector<int>ans;
         while(q.size()>0){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(int i=0;i<adj[x].size();i++){
                outdegree[adj[x][i]]--;
                if(outdegree[adj[x][i]] == 0) q.push(adj[x][i]);
            }
         }
         sort(ans.begin(),ans.end());
         return ans;
    }
};