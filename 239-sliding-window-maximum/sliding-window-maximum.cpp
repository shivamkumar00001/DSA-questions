class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n =nums.size();

        deque<int> q;

        int r =0;
        int l=0;
        vector<int> ans;
        while(r<n){
            while(q.size()>0 && q.back()<nums[r]){
                q.pop_back();
            }
            q.push_back(nums[r]);

            if(r-l+1>k){
                if(nums[l]==q.front())q.pop_front();
                l++;
            }
            if(r-l+1 == k){
                ans.push_back(q.front());
            }
            r++;
        }
        return ans;
    }
};