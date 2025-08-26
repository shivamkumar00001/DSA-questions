class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        // use ordered map instead of unordered_map
        map<int,int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int start = it->first;
            int cnt = it->second;

            if (cnt > 0) {
                // try to build k consecutive numbers starting from 'start'
                for (int i = 0; i < k; i++) {
                    int val = start + i;
                    if (mp[val] < cnt) return false;
                    mp[val] -= cnt;
                }
            }
        }
        return true;
    }
};
