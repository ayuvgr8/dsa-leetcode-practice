class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0; // Initialize the robot's position at the origin (0, 0).

        for (char move : moves) {
            // Update the position based on the current move.
            if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            } else if (move == 'L') {
                x--;
            } else if (move == 'R') {
                x++;
            }
        }

        // Check if the final position is the origin.
        return x == 0 && y == 0;
    }
};
