class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        vector<int> in(numCourses, 0);

        for(int i=0; i< pr.size(); i++){
            in[pr[i][1]]++;
        }
        
        vector<list<int>>graph(numCourses);

        for(int i =0;i<pr.size();i++){
            graph[pr[i][0]].push_back(pr[i][1]);
        }

        queue<int> q;
        
        for(int i=0; i<in.size();i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int count  =0;
        while(q.size()>0){
           int val = q.front();
           q.pop();
           count++;

           for(int v : graph[val]){
            in[v]--;
            if(in[v]== 0){
                q.push(v);
            }
           }
        }

        return count == numCourses;

        
    }
};