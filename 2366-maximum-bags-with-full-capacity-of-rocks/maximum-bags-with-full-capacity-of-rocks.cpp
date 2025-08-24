class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diff(n);
        
        // compute how much space is left in each bag
        for (int i = 0; i < n; i++) {
            diff[i] = capacity[i] - rocks[i];
        }

        // sort by required rocks
        sort(diff.begin(), diff.end());

        int count = 0;
        for (int d : diff) {
            if (d == 0) {  // already full
                count++;
            }
            else if (d <= additionalRocks) {
                additionalRocks -= d;
                count++;
            }
            else {
                break; // no more rocks can fill this bag
            }
        }
        return count;
    }
};
