class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         
         stack<int> st;
         vector<int> ans(nums1.size());
         unordered_map<int,int>mp;
         for(int i=nums2.size()-1;i>=0;i--){
             
             if(st.size()>0 && st.top()>nums2[i]){
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
             }
             else if(st.size()>0 ){
                while(st.size()>0 && st.top()<=nums2[i]){
                    st.pop();
                }
                if(st.size()>0){
                    mp[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
                else {
                    mp[nums2[i]] = -1;
                    st.push(nums2[i]);
                }
             }
             else if(st.size() ==0){
                   mp[nums2[i]] = -1;
                    st.push(nums2[i]);
             }
         }
         for(int i =0 ;i<nums1.size();i++){
            nums1[i] = mp[nums1[i]];
         }
         return nums1;
    }
};