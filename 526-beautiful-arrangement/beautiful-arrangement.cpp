class Solution {
public:

    void helper( int n , vector<int>& used, int &count,int ind){
        if(ind == n+1) {
            count+=1;
            return;
        }
        for(int i =1 ;i<=n;i++){
            if(used[i] ==-1) continue;

            if(i%ind ==0 || ind % i ==0){
            used[i] = -1;
            helper(n, used, count,ind+1);
            used[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        int  count =0;
        vector<int> used(n+1,0);
        helper(n, used, count,1);
        return count;
    }
};