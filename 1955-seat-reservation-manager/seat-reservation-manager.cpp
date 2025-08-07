class SeatManager {
public:
    int nextSeat;
    priority_queue<int, vector<int>, greater<int>> pq;

    SeatManager(int n) {
        nextSeat = 1;
    }

    int reserve() {
        if (!pq.empty()) {
            int seat = pq.top();
            pq.pop();
            return seat;
        }
        return nextSeat++;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
