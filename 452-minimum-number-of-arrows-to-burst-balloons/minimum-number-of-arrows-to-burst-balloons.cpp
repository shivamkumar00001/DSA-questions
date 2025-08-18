bool cmp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);
        int count =0;
        int lastend = points[0][1];
        for(int i=1;i<points.size();i++){
            if(lastend>=points[i][0]){
                count++;
            }
            else{
                lastend = points[i][1];
            }
        }

        return points.size()-count;
    }
};