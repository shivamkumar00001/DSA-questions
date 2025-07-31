class Solution {
public:

    typedef pair<int,int> p;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<p>pq;

        for(int i = 0 ;i< arr.size();i++){
            int y = abs(arr[i]-x);

            pq.push({y,arr[i]});

            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;

        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};