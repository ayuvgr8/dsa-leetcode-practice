class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        vector<double> arrival_times(n);
        for (int i = 0; i < n; i++) {
            arrival_times[i] = static_cast<double>(dist[i]) / speed[i];
        }

        sort(arrival_times.begin(), arrival_times.end());

        int count = 0;  // Initialize the count of eliminated monsters.
        double time = 0;  // Initialize the time counter.

        for (int i = 0; i < n; i++) {
            if (arrival_times[i] > time) {
                // If the current monster arrives after the time it takes to charge the weapon, we can eliminate it.
                count++;
                time += 1.0;  // Charge the weapon for the next minute.
            } else {
                // If the monster arrives before the weapon is charged, the game ends.
                break;
            }
        }

        return count;
    }
};

// vector<double> arrival_times(n); - Create a vector to store the arrival times for each monster.

// Loop through the monsters and calculate their arrival times by dividing the distance by the speed. Convert the result to a double to ensure precision.

// sort(arrival_times.begin(), arrival_times.end()); - Sort the arrival times in ascending order to prioritize eliminating monsters that arrive earlier.

// Initialize variables for counting eliminated monsters (count) and tracking the time (time).

// Iterate through the sorted arrival times.

// Check if the current monster arrives after the time it takes to charge the weapon (arrival_times[i] > time). If so, eliminate the monster and increment the count. Also, increase the time by 1 to represent charging the weapon for the next minute.

// If a monster arrives before the weapon is charged, the game ends, so break the loop.

// Return the count of eliminated monsters.

// You can use this C++ solution to solve the problem, and it should produce the correct results for the provided test cases.