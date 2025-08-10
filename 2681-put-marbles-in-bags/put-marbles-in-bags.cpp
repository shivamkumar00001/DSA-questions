class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int m = weights.size()-1;
        vector<int> pairs(m,0);
        for(int i =0;i<m;i++){
            pairs[i] = weights[i]+weights[i+1];
        }

        sort(pairs.begin(), pairs.end());
        long long max =0;
        long long min =0;
        for(int i =0;i<k-1;i++){
            min += pairs[i];
            max += pairs[m-1-i];
        } 

        return max-min;
    }
};