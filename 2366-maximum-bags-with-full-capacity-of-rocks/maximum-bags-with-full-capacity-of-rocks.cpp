bool cmp (pair<int,int>&a, pair<int,int>&b){
    return (a.first-a.second)<(b.first - b.second);
}
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<pair<int,int>> p;
        for(int i=0;i<capacity.size();i++){
            p.push_back({capacity[i],rocks[i]});
        }
        sort(p.begin(),p.end(),cmp);
        int count =0;
        for(int i=0;i<p.size();i++){
            int diff = p[i].first-p[i].second;
            if(diff>0){
                if(diff<=additionalRocks){
                    additionalRocks-= diff;
                    count++;
                }
            }
            else if(diff == 0){
                count++;
            }
        }
        return count;
    }
};