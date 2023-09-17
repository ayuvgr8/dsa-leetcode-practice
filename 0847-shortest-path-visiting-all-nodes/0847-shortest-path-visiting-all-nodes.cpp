// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) {
            return 0; // If there's only one node, we're already at the destination.
        }

        queue<pair<int, int>> q; // Queue for BFS, where each element is (current node, bitmask of visited nodes).
        vector<vector<int>> visited(n, vector<int>(1 << n, false)); // 2D array to track visited nodes and their states.
        
        // Initialize the BFS queue with all nodes as starting points.
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i}); // Each node is visited in its own path.
            visited[i][1 << i] = true; // Mark the node as visited with the corresponding bitmask.
        }

        int steps = 0; // Initialize the number of steps (moves).
        
        while (!q.empty()) {
            int qSize = q.size();
            
            for (int i = 0; i < qSize; ++i) {
                auto [node, bitmask] = q.front();
                q.pop();
                
                if (bitmask == (1 << n) - 1) {
                    return steps; // If all nodes have been visited, return the number of steps.
                }
                
                for (int neighbor : graph[node]) {
                    int nextBitmask = bitmask | (1 << neighbor); // Set the bit for the neighbor node.
                    
                    if (!visited[neighbor][nextBitmask]) {
                        q.push({neighbor, nextBitmask});
                        visited[neighbor][nextBitmask] = true;
                    }
                }
            }
            
            ++steps; // Increment the number of steps after exploring all neighbors at this level.
        }
        
        return -1; // Return -1 if no valid path exists.
    }
};

// int main() {
//     Solution solution;
    
//     vector<vector<int>> graph1 = {{1, 2, 3}, {0}, {0}, {0}};
//     int result1 = solution.shortestPathLength(graph1);
//     cout << "Shortest path length for graph1: " << result1 << endl;

//     vector<vector<int>> graph2 = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
//     int result2 = solution.shortestPathLength(graph2);
//     cout << "Shortest path length for graph2: " << result2 << endl;

//     return 0;
// }
