class Solution {
public:
    string ans;

    void helper(string &s, string &p, int n, int ind, vector<bool>& used) {
        if (ind > n) { // all positions filled
            if (ans.empty() || s < ans) ans = s;
            return;
        }

        for (int d = 1; d <= 9; d++) {
            if (used[d]) continue; // digit already taken

            if (ind == 0 || 
                (p[ind - 1] == 'I' && s[ind - 1] < d + '0') || 
                (p[ind - 1] == 'D' && s[ind - 1] > d + '0')) 
            {
                s[ind] = '0' + d;
                used[d] = true;
                helper(s, p, n, ind + 1, used);
                used[d] = false; // backtrack
            }
        }
    }

    string smallestNumber(string pattern) {
        int n = pattern.size();
        string s(n + 1, '0');
        vector<bool> used(10, false);
        helper(s, pattern, n, 0, used);
        return ans;
    }
};
