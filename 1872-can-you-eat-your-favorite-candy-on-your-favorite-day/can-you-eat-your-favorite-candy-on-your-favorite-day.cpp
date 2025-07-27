class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        
        int n =candiesCount.size();
        vector<long long > pre(n,0);
        pre[0] = candiesCount[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + candiesCount[i];
        }
        long long  ft =0;
        long long  fd =0;
        long long  dc =0;
        vector<bool> ans;
        for(int i = 0 ;i<queries.size();i++){

            ft = queries[i][0];
            fd = queries[i][1];
            dc = queries[i][2];

            if(ft>0 && (long long)dc*(fd+1)>pre[ft-1]){
                if(fd<pre[ft]){
                    ans.push_back(true);
                }
                else {
                    ans.push_back(false);
                }
            }
            else if(ft>0 && (long long)dc*fd<=pre[ft-1]){
                ans.push_back(false);
            }
            else if(ft == 0){
                if(dc*fd>pre[0]){
                    ans.push_back(false);
                }
                else{
                    ans.push_back(true);
                }
            }
        }

        return ans;
    }
};