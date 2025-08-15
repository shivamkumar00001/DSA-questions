class Solution {
public:
    typedef pair<char, int>p;
    string repeatLimitedString(string s, int l) {
        
        priority_queue<p> pq;
        unordered_map<char,int>mp;
        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto [a,b]: mp){
            pq.push({a,b});
        }
        string ans ="";
        while(pq.size()>0){
            auto [a,b] = pq.top();
            pq.pop();
            int x = min(l,b);
            for(int i =0 ;i< x;i++){
                ans+=a;
            }
            if(b-x>0){
                if(!pq.empty()){
                    auto [c,d] = pq.top();
                    pq.pop();
                    ans+=c;
                    d-=1;
                    if(d>0){
                        pq.push({c,d});
                    }
                    pq.push({a,b-x});
                }
                else break;
            }
        }

        return ans;
    }
};