class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        priority_queue<p, vector<p>, greater<p>> pq;
        
        for(auto x : mp){
            pq.push({x.second,x.first});
            if(pq.size()>k)pq.pop();
        }
        
        vector<int>ans;

        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};