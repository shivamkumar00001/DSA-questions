bool cmp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int N = intervals.size();
        vector<vector<int>>result;
        result.push_back(intervals[N-1]);

        for(int i= N-2;i>=0;i--){
            int n = result.size()-1;

            if(intervals[i][1]>=result[n][0]){
                result[n][0] = min(result[n][0],intervals[i][0]);
                result[n][1] = max(result[n][1],intervals[i][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};