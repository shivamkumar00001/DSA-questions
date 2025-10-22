class Solution {
public:
    vector<vector<int>> dp;
    int lcs ( vector<int>& nums, vector<int>& v, int i, int j){
        if(i == nums.size() || j == v.size()) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(nums[i] == v[j]){
            return dp[i][j] = 1 + lcs(nums, v, i+1, j+1);
        }
        else return dp[i][j] = max(lcs(nums, v,i+1,j), lcs(nums,v,i,j+1));
    }
    int lengthOfLIS(vector<int>& nums) {
        
        set<int>s;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        vector<int>v;
        for(auto x : s){
            cout<<x<<" ";
            v.push_back(x);
        }
        dp.resize(nums.size()+1, vector<int>(v.size()+1,-1));
        return lcs(nums, v, 0 , 0);
        

    }
};