// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> strength; // Vector to store row strength (number of soldiers, row index).

        // Calculate the strength of each row and store it in the 'strength' vector.
        for (int i = 0; i < mat.size(); ++i) {
            int count = 0; // Count of soldiers in the current row.
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 1) {
                    count++;
                } else {
                    break; // Stop counting when we encounter the first civilian.
                }
            }
            strength.push_back({count, i});
        }

        // Sort the 'strength' vector based on strength and row index.
        // If two rows have the same strength, the one with the lower index comes first.
        sort(strength.begin(), strength.end());

        vector<int> result; // Vector to store the final result.
        
        // Add the first 'k' row indices from the sorted 'strength' vector to the result.
        for (int i = 0; i < k; ++i) {
            result.push_back(strength[i].second);
        }

        return result;
    }
};

// int main() {
//     Solution solution;
    
//     vector<vector<int>> mat1 = {
//         {1, 1, 0, 0, 0},
//         {1, 1, 1, 1, 0},
//         {1, 0, 0, 0, 0},
//         {1, 1, 0, 0, 0},
//         {1, 1, 1, 1, 1}
//     };
//     int k1 = 3;

//     vector<int> result1 = solution.kWeakestRows(mat1, k1);
//     cout << "K weakest rows in mat1: ";
//     for (int row : result1) {
//         cout << row << " ";
//     }
//     cout << endl;

//     vector<vector<int>> mat2 = {
//         {1, 0, 0, 0},
//         {1, 1, 1, 1},
//         {1, 0, 0, 0},
//         {1, 0, 0, 0}
//     };
//     int k2 = 2;

//     vector<int> result2 = solution.kWeakestRows(mat2, k2);
//     cout << "K weakest rows in mat2: ";
//     for (int row : result2) {
//         cout << row << " ";
//     }
//     cout << endl;

//     return 0;
// }
