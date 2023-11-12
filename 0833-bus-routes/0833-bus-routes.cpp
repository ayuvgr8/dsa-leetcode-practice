// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <unordered_set>

class Solution {
public:
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) {
        if (source == target) {
            // If the source and target are the same, no need to take any buses
            return 0;
        }

        // Create a graph where each bus stop is connected to the buses that pass through it
        std::unordered_map<int, std::vector<int>> stopToBuses;
        for (int bus = 0; bus < routes.size(); ++bus) {
            for (int stop : routes[bus]) {
                stopToBuses[stop].push_back(bus);
            }
        }

        std::queue<int> q;  // Queue for BFS
        std::unordered_set<int> visitedBuses;  // Set to keep track of visited buses
        std::unordered_set<int> visitedStops;  // Set to keep track of visited bus stops

        // Start BFS from the source bus stop
        for (int bus : stopToBuses[source]) {
            q.push(bus);
            visitedBuses.insert(bus);
        }

        int numBuses = 0;  // To count the number of buses taken

        while (!q.empty()) {
            int size = q.size();
            ++numBuses;

            for (int i = 0; i < size; ++i) {
                int currentBus = q.front();
                q.pop();

                // Explore all bus stops visited by the current bus
                for (int stop : routes[currentBus]) {
                    if (stop == target) {
                        // If the target is reached, return the number of buses taken
                        return numBuses;
                    }

                    // Explore buses passing through the current bus stop
                    for (int nextBus : stopToBuses[stop]) {
                        if (visitedBuses.find(nextBus) == visitedBuses.end()) {
                            visitedBuses.insert(nextBus);
                            q.push(nextBus);
                        }
                    }

                    visitedStops.insert(stop);  // Mark the bus stop as visited
                }
            }
        }

        return -1;  // If the target is not reachable
    }
};
