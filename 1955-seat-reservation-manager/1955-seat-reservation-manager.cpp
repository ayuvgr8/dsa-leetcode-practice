
class SeatManager {
    set<int> availableSeats; // Use a set to keep track of available seats.

public:
    SeatManager(int n) {
        // Initialize available seats from 1 to n.
        for (int seat = 1; seat <= n; seat++) {
            availableSeats.insert(seat);
        }
    }

    int reserve() {
        if (!availableSeats.empty()) {
            int seatNumber = *availableSeats.begin(); // Get the smallest available seat.
            availableSeats.erase(seatNumber); // Remove it from the set.
            return seatNumber;
        }
        return -1; // No available seats.
    }

    void unreserve(int seatNumber) {
        availableSeats.insert(seatNumber); // Add the unreserved seat back to the set.
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */