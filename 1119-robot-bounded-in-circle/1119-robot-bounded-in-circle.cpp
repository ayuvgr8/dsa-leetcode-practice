class Solution {
public:
    bool isRobotBounded(string instructions) {
        // Initial position and direction
        int x = 0, y = 0; // (x, y) coordinates
        int dx = 0, dy = 1; // (dx, dy) represents the current direction (initially north)

        // Simulate the robot's movements
        for (char instruction : instructions) {
            if (instruction == 'G') {
                // Move forward in the current direction
                x += dx;
                y += dy;
            } else if (instruction == 'L') {
                // Turn 90 degrees to the left (anti-clockwise)
                int temp = dx;
                dx = -dy;
                dy = temp;
            } else if (instruction == 'R') {
                // Turn 90 degrees to the right (clockwise)
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
        }

        // Check if the robot returns to the initial position or is facing a different direction
        // If it's back at the origin or facing north (initial direction), it will form a circle
        return (x == 0 && y == 0) || !(dx == 0 && dy == 1);
    }
};
