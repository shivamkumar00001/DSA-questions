class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort (g.begin(),g.end());
        sort(s.begin(),s.end());
        int m = s.size();
        int n = g.size();
        int i = 0;
        int j =0;
        int count =0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                j++;
                i++;
                count++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};


