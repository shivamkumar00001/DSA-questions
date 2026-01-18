class Solution {
public:
    unordered_set<int>visited;
    void bfs (vector<vector<int>>& s, int src){

        
            for(int j= 0;j<s[src].size();j++){
                if(visited.find(s[src][j] )== visited.end()){
                    visited.insert(s[src][j]);
                    bfs(s, s[src][j]);
                }
        }

        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       
          bfs(rooms, 0);
          visited.insert(0);
          if(visited.size() == rooms.size()) return true;
          return false;
        
    }
};