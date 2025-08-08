class Solution {
public:
    
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;

        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string res = "";
        while(pq.size()>0){
            auto x = pq.top();
            pq.pop();

            if(pq.size()>0){
                auto y = pq.top();
                pq.pop();

                if((res.size()== 0 && x.first>=2) || (x.first>=2 && res[res.size()-1]!=x.second)){
                    res+=x.second;
                    res+=x.second;
                    x.first-=2;
                    if(x.first>0) pq.push({x.first,x.second});
                }
                else{
                    res+=x.second;
                    x.first-=1;
                    if(x.first>0) pq.push({x.first,x.second});
                }
                res+=y.second;
                y.first-=1;
                if(y.first>0) pq.push({y.first,y.second});
            }
            else{
                 if((res.size()== 0 && x.first>=2) || (x.first>=2 && res[res.size()-1]!=x.second)){
                    res+=x.second;
                    res+=x.second;
                    x.first-=2;
                    if(x.first>0) pq.push({x.first,x.second});
                }
                else{
                    res+=x.second;
                    x.first-=1;
                    if(x.first>0) pq.push({x.first,x.second});
                }
                break;
            }
        }
        return res;
    }
};