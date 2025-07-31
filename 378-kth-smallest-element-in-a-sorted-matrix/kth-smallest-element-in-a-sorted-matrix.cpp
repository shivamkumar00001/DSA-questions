class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        priority_queue<int> pq;
        for(int i =0;i<n;i++){
            pq.push(matrix[i][i]);
            if(pq.size()>k){
                    pq.pop();
                }
            for(int j =i+1;j<n;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
                pq.push(matrix[j][i]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};