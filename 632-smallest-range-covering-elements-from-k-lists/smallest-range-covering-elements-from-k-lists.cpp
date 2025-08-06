class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<p, vector<p>, greater<p>> pq;

        int min =0;
        int maxi = INT_MIN;
        int start =INT_MAX;
        int end = INT_MIN;

        for(int i = 0 ;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            maxi = max(nums[i][0],maxi);
        }
        start  = nums[pq.top().second.first][pq.top().second.second];
        end = maxi;

        while(true){
            auto x = pq.top();
            pq.pop();
            if(nums[x.second.first].size()-1 == x.second.second){
                break;
            }
            
            pq.push({nums[x.second.first][x.second.second+1],{x.second.first,x.second.second+1}});
            maxi = max(nums[x.second.first][x.second.second+1],maxi);
            min = pq.top().first;
            if(maxi-min < end-start){
                start = min;
                end = maxi;
            }
        }
        return {start,end};
    }
};