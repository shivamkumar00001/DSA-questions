class Solution {
public:

   vector<int>ans;
   void helper(int n, int k, int &num, int ind){
    if(ind == n){
        ans.push_back(num);
        return;
    }

    for(int i =0;i<=9;i++){
        if(i == 0 && num !=-1 && (num%10) == k){
            num = num*10;
            helper(n, k, num,ind+1);
            num = num/10;
        }
        else if( i== 0 && num == -1) continue;
        else{
            if(num == -1){
                num = i;
                helper(n,k,num,ind+1);
                num =-1;
            }
            else{
                if(abs(num%10-i) == k){
                    num = num*10 +i;
                    helper(n,k,num,ind+1);
                    num = num/10;
                }
            }
        }
    }
   }
   vector<int> numsSameConsecDiff(int n, int k) {
        int num=-1;
        helper(n,k,num,0);
        return ans;
    }
};