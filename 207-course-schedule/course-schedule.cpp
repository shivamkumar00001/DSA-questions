class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
         
         vector<vector<int>> adj(numCourses);
         vector<int> indegree(numCourses);
         for(int i=0;i<p.size();i++){
             
             adj[p[i][0]].push_back(p[i][1]);
             indegree[p[i][1]]++;

         }

         queue<int>q;
         for(int i=0;i<indegree.size();i++){
             if(indegree[i] == 0) q.push(i);
         }

         int count =0;
         while(q.size()>0){
              int val = q.front();
              q.pop();
              count++;
              for(int a : adj[val]){
                 indegree[a]--;
                 if(indegree[a] == 0){
                    q.push(a);
                 }
              }


         }

         return count==numCourses;

    }
};