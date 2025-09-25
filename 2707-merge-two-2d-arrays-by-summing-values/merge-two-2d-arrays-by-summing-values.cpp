class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;

        while (i < nums1.size() || j < nums2.size()) {
            if (i < nums1.size() && j < nums2.size() && nums1[i][0] == nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if (j == nums2.size()) {   // nums2 finished
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else if (i == nums1.size()) {   // nums1 finished
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
            else if (nums1[i][0] < nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else { // nums1[i][0] > nums2[j][0]
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }

        return ans;
    }
};
