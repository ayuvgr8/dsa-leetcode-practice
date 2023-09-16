// // #include <iostream>
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
        
        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            auto [curEffort, curPos] = pq.top();
            pq.pop();
            
            int x = curPos.first;
            int y = curPos.second;
            
            if (x == rows - 1 && y == cols - 1) {
                return curEffort;
            }
            
            if (curEffort > effort[x][y]) {
                continue;
            }
            
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int diff = abs(heights[x][y] - heights[nx][ny]);
                    int newEffort = max(curEffort, diff);
                    
                    if (newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
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

