class Solution {
public:
    
    int find( int x, vector<int>&parent){

        return parent[x] = parent[x] == x? x: find(parent[x], parent);
    }
    bool un(vector<int> &parent, vector<int> &rank, int a, int b){

        a = find(a, parent);
        b = find(b ,parent);
        if(a == b) return false;

        if(rank[a]>rank[b]){
            rank[a]++;
            parent[b] = a;
        }

        else{
            rank[b]++;
            parent[a] = b;
        }

        return true;
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>parent(n);
        vector<int> rank(n,1);

        for(int i =0; i<n;i++){
            parent[i] = i;
        }

        vector<vector<int>> v;

        for(int i =0; i< n;i++){
            for(int j =i+1; j<n;j++){
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                v.push_back({i,j,d});
            }
        }

        int edgect =0;
        int i =0;
       sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b){
          return a[2] < b[2];
       });

        int sum =0;
        while(edgect<n-1 && i<v.size()){
            int a = v[i][0];
            int b = v[i][1];
            int wt = v[i][2];
            if(un(parent,rank,a,b)){
                 sum+= wt;
                 edgect++;
            }
            i++;
        } 

        return sum;
    }
};