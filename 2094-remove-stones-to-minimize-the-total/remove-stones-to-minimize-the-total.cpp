#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end()); // heapify directly
        
        while (k-- > 0) {
            int x = pq.top();
            pq.pop();
            pq.push(x - x / 2); // remove floor, use int division
        }
        
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
