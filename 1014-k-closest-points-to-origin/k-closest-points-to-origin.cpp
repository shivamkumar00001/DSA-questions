class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        

        priority_queue<pair<double , p>>pq;

        for(int i = 0 ; i< points.size() ;i++){
            int a = points[i][0];
            int b = points[i][1];
            double x = sqrt((long long)a*a + (long long)b*b);
            pq.push({x , {a,b}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;

        while(pq.size()>0){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};