class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n), next(n);
        stack<int> st;

        // Previous Smaller Element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack
        while(!st.empty()) st.pop();

        // Next Smaller Element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + (left * right % mod) * arr[i] % mod) % mod;
        }

        return sum;
    }
};