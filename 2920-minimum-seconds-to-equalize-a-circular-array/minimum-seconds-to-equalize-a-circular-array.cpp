class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) mp[nums[i]].push_back(i);

        int mini = INT_MAX;

        for (auto &x : mp) {
            int maxi = 0;
            vector<int> &v = x.second;

            // gaps between consecutive occurrences
            for (int i = 0; i + 1 < (int)v.size(); ++i) {
                maxi = max(maxi, (v[i+1] - v[i]) / 2);   // floor division
            }

            // wrap-around gap
            maxi = max(maxi, (n - v.back() + v[0]) / 2); // floor division

            mini = min(mini, maxi);
        }
        return mini;
    }
};
