class Solution {
public:
    typedef pair<int,int>p;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<p> pq;

        int count =0;
        for(int i=0;i<mat.size();i++){
            count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1){
                    count++;
                }
                else break;
            }
            pq.push({count,i});
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans(k,0);
        while(pq.size()>0){
            ans[k-1] = pq.top().second;
            pq.pop();
            k--;
        }
        
        return ans;

    }
};