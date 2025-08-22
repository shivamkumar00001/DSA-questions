class Solution {
public:
    
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = reward1.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            pq.push(reward1[i]-reward2[i]);
            if(pq.size()>k)pq.pop();
            maxi+=reward2[i];
        }
        while(pq.size()>0){
            maxi+=pq.top();
            pq.pop();
        }
        return maxi;
    }
};