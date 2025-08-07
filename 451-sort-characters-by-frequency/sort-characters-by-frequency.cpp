class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans;
        priority_queue<pair<int,char>>pq;
        for(char c : s){
            mp[c]++;
        }
        for(auto x : mp){
            pq.push({x.second,x.first});
        }
        while(pq.size()>0){
            auto x = pq.top();
            int n = x.first;
            while(n>0){
                ans+=x.second;
                n--;
            }
            pq.pop();
        }
        return ans;
    }
};