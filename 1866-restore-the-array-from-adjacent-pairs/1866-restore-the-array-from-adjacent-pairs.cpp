class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        // Build a graph using the information from adjacentPairs
        for (const auto& pair : adjacentPairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        int n = adjacentPairs.size() + 1;  // The size of the original array

        // Find the first element by checking which node has only one neighbor
        int start = 0;
        for (const auto& entry : graph) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }

        vector<int> result;  // To store the final result

        // Perform a Depth-First Search (DFS) traversal to reconstruct the array
        dfs(graph, start, result, n);

        return result;
    }

private:
    void dfs(unordered_map<int, vector<int>>& graph, int node, vector<int>& result, int n) {
        if (result.size() == n) {
            // If the result array is complete, return
            return;
        }

        result.push_back(node);  // Add the current node to the result

        // Traverse neighbors of the current node
        for (int neighbor : graph[node]) {
            graph[neighbor].erase(find(graph[neighbor].begin(), graph[neighbor].end(), node));
            // Recursively explore the neighbor
            dfs(graph, neighbor, result, n);
        }
    }
};
