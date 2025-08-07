class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        pq.push(amount[0]);
        pq.push(amount[1]);
        pq.push(amount[2]);
        int count =0;
        while(pq.size()!=0){
            int x = pq.top();
            pq.pop();
            if(x == 0) continue;
            if(pq.size()!=0){
            int y = pq.top();
            pq.pop();
            x--;
            y--;
            if(x>0) pq.push(x);
            if(y>0) pq.push(y);
            }
            else {
                x--; 
                if(x>0) pq.push(x);
            }
            count++;
        }
        return count;
    }
};