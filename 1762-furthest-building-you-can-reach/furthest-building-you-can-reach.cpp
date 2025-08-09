class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        if(heights.size() == 1) return 0;
        int n = heights.size();
        int i=1;
        while(i<n){
            if(heights[i]>heights[i-1]){
                pq.push(heights[i]-heights[i-1]);
            }

            if(pq.size()>ladders){
                bricks-= pq.top();
                pq.pop();
            }
            if(bricks<0) break;
            i++;
        }
        return i-1;
    }
};