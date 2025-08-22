class Solution {
public:
    
    typedef pair<int,int> p;
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<p, vector<p>, greater<p>>pq;
        int n = reward1.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            pq.push({reward1[i]-reward2[i],i});
            if(pq.size()>k)pq.pop();
            maxi+=reward2[i];
        }
        while(pq.size()>0){
            maxi+=reward1[pq.top().second];
            maxi-=reward2[pq.top().second];
            reward2[pq.top().second]=-1;
            pq.pop();
        }
        return maxi;
    }
};