class Solution {
public:

    int helper( int &n , string original, string copy){
        int c = copy.size();
        int o = original.size();
        if(o == n) return 0;
        if(c+o>n) return INT_MAX/2;
        int ans = INT_MAX;
        if(o+c<=n && copy != ""){
           ans = min(ans, 1+ helper(n, original+copy,copy));
        }
        if(o!=c)
        ans = min(ans, 1+helper(n, original, original));
        return ans;
    }
    int minSteps(int n) {
        
        return helper(n, "A", "");
    }
};