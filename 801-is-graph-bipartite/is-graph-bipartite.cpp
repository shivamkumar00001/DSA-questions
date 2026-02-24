class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
         vector<int> color(graph.size(),-1);
         queue<int>q;
    
        for(int i =0 ;i< graph.size(); i++){
            
            if(color[i] != -1) continue;
            q.push(i);
            color[i] = 0;
            
            while(q.size()>0){
                
                int curr = q.front();
                q.pop();
                for(int n : graph[curr]){

                    if(color[n] == -1){
                        color[n] = 1- color[curr];
                        q.push(n);
                    }
                    else if(color[n] == color[curr]) return false;
                }

            }
        }

        return true;

    }
};