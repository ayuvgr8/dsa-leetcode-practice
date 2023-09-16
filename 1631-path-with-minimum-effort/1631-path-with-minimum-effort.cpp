// #include <iostream>
// #include <vector>
// #include <queue>
// #include <limits>
// using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Define the possible directions for movement: up, down, left, and right.
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX)); // Initialize the effort matrix.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        effort[0][0] = 0; // Starting cell has an effort of 0.
        pq.push({0, {0, 0}}); // Push the starting cell into the priority queue.
        
        while (!pq.empty()) {
            auto [curEffort, curPos] = pq.top(); // Get the cell with the minimum effort.
            pq.pop();
            
            int x = curPos.first; // Current cell's row.
            int y = curPos.second; // Current cell's column.
            
            if (x == rows - 1 && y == cols - 1) {
                return curEffort; // If we reach the bottom-right cell, return the effort.
            }
            
            if (curEffort > effort[x][y]) {
                continue; // Skip if we have already found a better path to this cell.
            }
            
            for (auto& dir : directions) {
                int nx = x + dir[0]; // Next cell's row.
                int ny = y + dir[1]; // Next cell's column.
                
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int diff = abs(heights[x][y] - heights[nx][ny]); // Calculate height difference.
                    int newEffort = max(curEffort, diff); // Determine new effort required.
                    
                    if (newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort; // Update the effort for the next cell.
                        pq.push({newEffort, {nx, ny}}); // Push the next cell into the priority queue.
                    }
                }
            }
        }
        
        return -1; // Return -1 if no path is found.
    }
};

// int main() {
//     Solution solution;
//     vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
//     int result = solution.minimumEffortPath(heights);
    
//     cout << "Minimum effort required: " << result << endl;

//     return 0;
// }

