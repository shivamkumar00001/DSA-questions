class Solution {
public:
    
    int find( int a, vector<int> &parent){

        return parent[a] = parent[a] == a? a: find(parent[a], parent);
    }

    void dsu( int a, int b, vector<int>& parent, vector<int> &rank){
        a = find(a, parent);
        b = find(b, parent);

        if(a == b) return;

        if(rank[a]>rank[b]){
            parent[b] = a;
            rank[a]++;
        }
        else {
            parent[a] = b;
            rank[b]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         
         int n = isConnected.size();
         vector<int>parent (isConnected.size());

         for(int i=0; i<n; i++){
            parent[i] = i;
         }
         vector<int> rank(n, 1);

         for(int i = 0; i<n ;i++){
            for(int j = 0 ; j<n; j++){
                if(isConnected[i][j] == 1){
                    dsu(i,j,parent, rank);
                }
            }
         }
         unordered_set<int> st;
         for(int i=0; i<n;i++){
            st.insert(find(i, parent));
         }

         return st.size();
    }
};