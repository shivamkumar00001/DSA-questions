class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0,k=0,a=0;
    
        for(int i=a;i<prices.size();i++)
        {
                if((prices[i]-prices[k])>max)
                {
                    max=(prices[i]-prices[k]);
                }
            if(i==prices.size()-1)
            {
                k++;
                a+=1;
                i=a;
            } 
            if(k==prices.size()-1)
            break ;  
            
        }

        return max;
    }
};
