#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq; // max-heap: (value, index)
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i}); // push current element with index

            // Remove elements out of current window
            while (pq.top().second <= i - k) {
                pq.pop();
            }

            // Record max after first k elements
            if (i >= k - 1) {
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};
