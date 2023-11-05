class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int current = arr[0];  // Initialize the current winner with the first element
        int winCount = 0;      // Initialize the win count
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > current) {
                current = arr[i];  // If the current element wins, update the current winner
                winCount = 1;      // Reset the win count to 1
            } else {
                winCount++;        // If the current element loses, increment the win count
            }
            
            if (winCount == k) {
                return current;  // If the win count reaches k, the current winner is the overall winner
            }
        }
        
        return current;  // If no winner is found after iterating through the array, the last winner is the overall winner
    }
};
