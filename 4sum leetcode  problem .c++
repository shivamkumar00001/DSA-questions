class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        for (int i = 0; i < nums.size()-1; i++) {

            for (int j = i+1; j < nums.size()-1; j++) {

                int l = j+1;
                int r = nums.size() - 1;

                if(i>0 && nums[i-1]==nums[i] )continue;

                while (l < r) {
                    
                   long long  int sum = (long long )nums[i] + (long long)nums[j] + (long long) nums[l] + (long long )nums[r];

                    if (sum == target) {
                        vector<int> temp= {nums[i], nums[j], nums[l], nums[r]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                        l++;
                        r--;
                        while(l<r && nums[l]==nums[l-1]&& l>0){
                            l++;
                        }
                        while(l<r && nums[r]==nums[r+1] ){
                            r--;
                        }
                    }
                    else if( sum<target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};
