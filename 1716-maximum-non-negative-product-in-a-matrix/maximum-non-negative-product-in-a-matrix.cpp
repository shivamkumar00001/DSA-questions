class Solution {
public:
    int mod = 1000000007;
    int m,n; 
    vector<vector<pair<long long, long long>>>dp;
    pair<long long,long long > helper(vector<vector<int>>& grid, int i, int j){
       
       if(i == m-1 && j == n-1) return {grid[i][j], grid[i][j]};

       if(i >= m || j >= n) return {LLONG_MIN,LLONG_MAX};
       long long maxi =LLONG_MIN;
       long long mini = LLONG_MAX;
       
       if(dp[i][j].first != LLONG_MIN) 
            return dp[i][j];
       pair<long long,long long>val1 = helper(grid,i+1,j);
       pair<long long,long long>val2 = helper(grid,i,j+1);
       
    
       vector<long long>val;

       if(val1.first!=LLONG_MIN){
         val.push_back(grid[i][j]*val1.first);
         val.push_back(grid[i][j]*val1.second);
       }

       if(val2.first!= LLONG_MIN){
        val.push_back(grid[i][j]*val2.first);
        val.push_back(grid[i][j]*val2.second);
       }

       for(auto v : val){
          
          maxi = max(maxi,v);
          mini = min(mini,v);
       }
       
       return dp[i][j] = {maxi,mini};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(grid.size(), vector<pair<long long,long long>>(grid[0].size(),{LLONG_MIN, LLONG_MAX}));
        pair<long long,long long> val = helper(grid, 0, 0);
        if(val.first<0) return -1;
        return val.first% mod;
    }
};