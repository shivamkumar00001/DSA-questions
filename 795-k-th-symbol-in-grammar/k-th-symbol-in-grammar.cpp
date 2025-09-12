class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1) return 0;
        int x;
        if(k%2 == 0){
            x = kthGrammar(n, k/2);
            if(x == 0) return 1;
            else return 0;
        }
        else{
            x = kthGrammar(n, (k+1)/2);
            return x;
        }
    }
};