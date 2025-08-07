class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        int n = score.size();
        vector<string>ans(n);
        
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        int idx = 1;
        while(pq.size()>0){
            auto x = pq.top();
            pq.pop();
            if(idx == 1){
                ans[x.second] = "Gold Medal";
            }
            else if(idx == 2){
                ans[x.second] = "Silver Medal";
            }
            else if(idx == 3){
                ans[x.second] = "Bronze Medal";
            }
            else{
                ans[x.second] = to_string(idx);
            }
            idx++;
        }
        return ans;
    }
};