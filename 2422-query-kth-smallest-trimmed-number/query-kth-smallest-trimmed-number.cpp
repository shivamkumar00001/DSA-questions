class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for (auto &q : queries) {
            int k = q[0], trim = q[1];
            priority_queue<pair<string,int>>pq;

            for(int i =0 ;i< nums.size();i++){
                string trimmed = nums[i].substr(nums[i].size()-trim);

                pq.push({trimmed,i});

                if(pq.size()>k) pq.pop();

            }

            ans.push_back(pq.top().second);
        }
        return ans;
    }
};