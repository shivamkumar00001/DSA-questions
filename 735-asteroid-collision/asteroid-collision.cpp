class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
           
        stack<int> st;

        for(int i=0;i<arr.size();i++){
            
            if(arr[i]>0){st.push(arr[i]);}
            else {
                while(st.size()>0 && st.top()>0 && st.top()< -1*arr[i])st.pop();
                 if(!st.empty() && st.top() == -arr[i]){
                    st.pop(); 
                }
                else if(st.empty() || st.top() < 0){
                    st.push(arr[i]);
                }
            }
        }  
        vector<int> ans;
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};