class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<long long> numsEven, numsOdd, targetEven, targetOdd;

        for (int x : nums) {
            if (x % 2 == 0) numsEven.push_back(x);
            else numsOdd.push_back(x);
        }

        for (int x : target) {
            if (x % 2 == 0) targetEven.push_back(x);
            else targetOdd.push_back(x);
        }

        sort(numsEven.begin(), numsEven.end());
        sort(numsOdd.begin(), numsOdd.end());
        sort(targetEven.begin(), targetEven.end());
        sort(targetOdd.begin(), targetOdd.end());

        long long op = 0;

       
        for (int i = 0; i < numsEven.size(); i++) {
            long long diff = abs(numsEven[i] - targetEven[i]);
            op += (diff / 2);  
        }

       
        for (int i = 0; i < numsOdd.size(); i++) {
            long long diff = abs(numsOdd[i] - targetOdd[i]);
            op += diff / 2;
        }

     
        return op / 2;
    }
};
