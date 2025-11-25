class Solution {
public:
    int reverse(int x) {
        bool p = true;

        if(x<0) p=false;

        long long a = x;
        a = (a<0)?-a:a;
        long long ans =0;
        while (a>0){
            int y  = a%10;
            a = a/10;
            ans = ans*10 + y; 
        }

        if(p == false){
            if(-1*ans < INT_MIN) return 0;
            else return -1*ans;
        };
        
        if(ans>INT_MAX) return 0;
        return ans;
    }
};