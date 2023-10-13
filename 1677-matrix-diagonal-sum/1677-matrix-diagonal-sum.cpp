class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(); // Get the size of the square matrix
        int sum = 0; // Initialize the sum variable

        for (int i = 0; i < n; i++) {
            // Add the element along the primary diagonal
            sum += mat[i][i];

            // Add the element along the secondary diagonal (if not part of the primary diagonal)
            if (i != n - 1 - i) {
                sum += mat[i][n - 1 - i];
            }
        }

        return sum; // Return the total sum
    }
};
