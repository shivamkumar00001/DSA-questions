class Solution {
public:

   int find( int a, vector<int>& parent){
      return parent[a] = parent[a] == a? a: find(parent[a], parent); 
   }

   void unite( int x, int y , vector<int>& parent, vector<int>& rank){
        
        x = find(x, parent);
        y = find(y, parent);

        if(x == y) return;

        if(rank[x]>rank[y]){
            parent[y] = x;
            rank[x]++;
        }
        else {
            parent[x] = y;
            rank[y]++;
        }
        return;
   }
   
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size()<n-1) return -1;
        vector<int> parent(n,0);
        vector<int>rank(n,1);

        for(int i =0; i<n ;i++){
            parent[i] = i;
        }
        for(auto c : connections){

            unite(c[0],c[1], parent, rank);
        }
        
        int count =0;
        for(int i =0 ;i< parent.size(); i++){

            if(find(i,parent) == i){
                count++ ;
            }
        } 
        cout << count;
        return count -1;

    }
};