class Solution {
public:
    int bestClosingTime(string customers) {
        

        int maxprofit =0;
        int profit =0;
        int n= customers.size();
        int hour =0;
        for(int i=0;i<n;i++){
            if(profit>maxprofit){
                hour = i;
                maxprofit = profit;
            }

            if(customers[i] == 'Y'){
                profit+=1;
            }
            else if(customers[i] == 'N'){
                profit-=1;
            }
            
        }
        if(profit>maxprofit){
                hour = n;
                maxprofit = profit;
            }

        return hour;
    }
};