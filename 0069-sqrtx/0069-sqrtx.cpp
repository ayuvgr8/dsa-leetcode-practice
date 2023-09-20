// #include <iostream>
// using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x; // If x is 0 or 1, the square root is x itself.
        }

        int left = 1; // Initialize the left boundary of the binary search.
        int right = x; // Initialize the right boundary of the binary search.
        int result = 0; // Initialize the result variable to store the square root.

        // Perform binary search to find the square root.
        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the middle value.

            // Check if the square of the middle value is equal to x.
            if (mid == x / mid) {
                return mid;
            }

            // If the square of the middle value is less than x, update the left boundary.
            if (mid < x / mid) {
                left = mid + 1;
                result = mid; // Store the potential result.
            } else {
                // If the square of the middle value is greater than x, update the right boundary.
                right = mid - 1;
            }
        }

        return result; // Return the square root rounded down to the nearest integer.
    }
};

// int main() {
//     Solution solution;

//     int x1 = 4;
//     int result1 = solution.mySqrt(x1);
//     cout << "Result 1: " << result1 << endl;

//     int x2 = 8;
//     int result2 = solution.mySqrt(x2);
//     cout << "Result 2: " << result2 << endl;

//     return 0;
// }
