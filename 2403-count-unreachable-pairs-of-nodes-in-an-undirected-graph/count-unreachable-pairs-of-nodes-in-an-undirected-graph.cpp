class Solution {
public:
    
    int findP(int x, vector<int> &parent){
        if(parent[x] == x) return x;
        return  findP(parent[x], parent);
    }

    void dsu(int a, int b, vector<int> &parent, vector<int> &size){
        a = findP(a, parent);
        b = findP(b, parent);

        if(a == b) return;

        if(size[a] > size[b]){
            parent[b] = a;
            size[a] += size[b];
        }
        else{
            parent[a] = b;
            size[b] += size[a];
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), size(n,1);
        for(int i=0;i<n;i++) parent[i] = i;

        for(auto &e : edges){
            dsu(e[0], e[1], parent, size);
        }

        vector<long long> comps;
        for(int i=0;i<n;i++){
            if(parent[i] == i){
                comps.push_back(size[i]);
            }
        }

        long long ans = 0, sum = 0;
        for(long long c : comps){
            ans += c * sum;
            sum += c;
        }
        return ans;
    }
};
