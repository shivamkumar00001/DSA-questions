class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        
        vector<pair<int,int>> nums;
        for(int i=0; i<n; i++) {
            nums.push_back({nums2[i], i});
        }
        sort(nums.begin(), nums.end());
        
        vector<int> ans(n);
        int j = 0;        // smallest in nums2
        int k = n - 1;    // largest in nums2
        
        for(int i=0; i<n; i++) {
            if(nums1[i] > nums[j].first) {
                ans[nums[j].second] = nums1[i];
                j++;
            } else {
                ans[nums[k].second] = nums1[i];
                k--;
            }
        }
        
        return ans;
    }
};
