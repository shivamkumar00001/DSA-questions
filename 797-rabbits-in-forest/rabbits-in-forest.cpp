class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int>mp;
         int ans=0;
        for(auto x : answers){
            if(!mp[x+1]){
                ans+=x+1;
                if(x==0) continue;
                mp[x+1] =1;
            }
            else{
                mp[x+1] +=1;
                if(x+1 == mp[x+1]){
                    mp.erase(x+1);
                }
            }
        }
        return ans;
    }
};