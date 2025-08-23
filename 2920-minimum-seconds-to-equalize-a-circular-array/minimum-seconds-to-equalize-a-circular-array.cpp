class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // store indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        if (mp.size()==1) return 0;
        int mini = INT_MAX;

        for (auto x : mp) {
            int maxi = 0;
            vector<int> v = x.second;

            // check gaps between consecutive occurrences
            for (int i = 0; i < v.size() - 1; i++) {
                maxi = max(maxi, (int)ceil((v[i+1] - v[i]) / 2));
            }

            // check circular gap (wrap-around)
            maxi = max(maxi, (int)ceil((n - v.back() + v[0]) / 2));

            mini = min(mini, maxi);
        }

        return mini;
    }
};
