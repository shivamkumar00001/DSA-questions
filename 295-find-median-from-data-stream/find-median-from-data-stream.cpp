class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int , vector<int> , greater<int>> pq2;
    int n1;
    int n2;

    MedianFinder() {
        n1 = 0;
        n2 = 0;
    }

    void addNum(int num) {
       if(n1 == 0 || pq1.top()>num){
        pq1.push(num);
        n1++;
       }
       else{
        pq2.push(num);
        n2++;
       }

       if(n1>n2+1){
        pq2.push(pq1.top());
        pq1.pop();
        n2++;
        n1--;
       }
       else if(n2>n1+1){
        pq1.push(pq2.top());
        pq2.pop();
        n1++;
        n2--;
       }
    }

    double findMedian() {
        if(n1 == n2){
            return (pq1.top()+pq2.top())/2.0;
        }

        else{
            if(n1>n2){
                return pq1.top();
            }
            else {
                return pq2.top();
            }
        }
    }
};
