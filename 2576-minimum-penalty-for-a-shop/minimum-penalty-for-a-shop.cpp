class Solution {
public:
    int bestClosingTime(string customers) {
         
         int min=INT_MIN;
         int profit=0;
         int n=customers.size();
         int ans=0;

        //  for(int i=0;i<n;i++){
        //     if(customers[i]=='y'){
        //         penalty++;
        //     }
          
        //  }

         for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                if(profit>min){
                    min=profit;
                    ans=i;
                }
                profit++;
            }
            else if(customers[i]=='N'){
                if(profit>min){
                    min=profit;
                    ans=i;
                }
                 profit--;
            }
         }
         if(profit>min){
            ans=n;
         }
         return ans;
    }
};