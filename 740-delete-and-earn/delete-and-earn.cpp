class Solution {
public:
    
    // same to house robber 


    // int solve(unordered_map<int,int>& mp){

    //     if(mp.size()== 0) return 0;
    //     int result =0;
    //     for(auto [x,y] : mp){

    //         auto m = mp;
    //         if(m.find(x-1)!= m.end())m.erase(x-1);
    //         if(m.find(x+1)!= m.end())m.erase(x+1);
    //         m[x]--;
    //         if(m[x] == 0) m.erase(x);
    //         result = max(result,x+solve(m));
    //     }
    //     return result;
    // }
    int deleteAndEarn(vector<int>& nums) {

        unordered_map<int,int>mp;
        int maxNum=0;
        for(auto x:nums){
            mp[x]+=x;
            maxNum = max(maxNum,x);
        }
        // return solve(mp);
        vector<int>dp(maxNum+1,0);

        dp[1] = mp[1];

        for(int i=2;i<=maxNum;i++){
            dp[i] = max(dp[i-1],dp[i-2]+mp[i]);
        }

        return dp[maxNum];
    }
};