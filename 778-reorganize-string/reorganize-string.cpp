class Solution {
public:
    string reorganizeString(string s){
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int> mp;
        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto x: mp){
            pq.push({x.second,x.first});
        }
        string res = "";
        while(pq.size()>0){
            auto x = pq.top();
            pq.pop();
            if(res == "" || res[res.size()-1] != x.second){
                res+=x.second;
                x.first-=1;
            }
            if(pq.size()>0){
                auto y = pq.top();
                pq.pop();
                if(res[res.size()-1] != y.second){
                res+=y.second;
                y.first-=1;
            }
            if(y.first>0) pq.push({y.first,y.second});
            }
            else{
                break;
            }
            if(x.first>0) pq.push({x.first,x.second});
        }
        return res.size() == s.size()?res:"";
    }
};