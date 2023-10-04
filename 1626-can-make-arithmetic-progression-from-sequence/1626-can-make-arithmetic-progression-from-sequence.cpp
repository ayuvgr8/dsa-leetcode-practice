class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // Sort the array in ascending order.
        int diff = arr[1] - arr[0]; // Calculate the common difference between the first two elements.

        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false; // If the difference between any two consecutive elements is not equal to the common difference, return false.
            }
        }

        return true; // If all differences are equal to the common difference, return true.
    }
};
