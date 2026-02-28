class Solution {
public:
    
    int find(int x ,vector<int>&parent){
        return parent[x] = parent[x]==x?x:find(parent[x],parent);
    }

    void unite(int x, int y, vector<int>&parent,vector<int>& rank){
        
        x = find(x, parent);
        y = find(y, parent);

        if(x == y) return;

        if(rank[x]>rank[y]){
            parent[y] = x;
            rank[x]++;
        }

        else{
            parent[x] = y;
            rank[y]++;
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
       
       int maxrow = 0;
       int maxcol = 0;

       for(int i=0;i<stones.size();i++){
          maxrow = max(maxrow, stones[i][0]);
          maxcol = max(maxcol, stones[i][1]);
       }
       int n = maxrow+maxcol+2;
        vector<int>parent(n);
        vector<int>rank(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        unordered_set<int>stone;
        for(int i =0; i<stones.size(); i++){
            int r = stones[i][0];
            int c = stones[i][1]+maxrow+1;
            unite(r,c,parent,rank);
            stone.insert(r);
            stone.insert(c);
        }

        int count =0;
        for(auto s : stone){
            if(find(s,parent) == s){
                count++;
            }
        }

        return stones.size()-count;
    }
};