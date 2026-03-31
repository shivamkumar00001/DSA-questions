class Solution {
public:

    // int helper( vetor<int> & prices, int ind){
        
    //     if(ind == prices.size()) return 0;

    //     int profit =0;
        
    //     profit = max(profit, helper(prices, ind+1))
    // }
    int maxProfit(vector<int>& prices) {
        
        // int mini = prices[0];
        // int profit = 0;

        // for(int i=1;i<prices.size();i++){
        //     if(prices[i]>mini){
        //         profit = max(profit,prices[i]-mini);
        //     }
        //     else mini = prices[i];
        // }
        // return profit;
        
        int mini = INT_MAX;
        int ans=0;
        for(int i =0 ;i< prices.size();i++){
            if(mini>prices[i]){
                 mini = prices[i] ;
            }
            else {
                   ans = max(ans, prices[i]-mini);
            }
        }
        return ans;
        // return helper(prices, 0);
    }
};