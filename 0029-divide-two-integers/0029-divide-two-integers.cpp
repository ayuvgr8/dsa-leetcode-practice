// #include <iostream>
// #include <cmath>
// using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle special cases where the result might exceed the 32-bit signed integer range.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // If dividing INT_MIN by -1, return INT_MAX to avoid overflow.
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN; // If dividing INT_MIN by 1, return INT_MIN.
        }

        // Determine the sign of the result.
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1; // XOR determines if signs are different.

        long long ldividend = abs(static_cast<long long>(dividend)); // Convert dividend to long long and take absolute value.
        long long ldivisor = abs(static_cast<long long>(divisor));   // Convert divisor to long long and take absolute value.

        long long quotient = 0; // Initialize the quotient as a long long to handle potential overflow.
        while (ldividend >= ldivisor) { // Perform division until dividend is smaller than divisor.
            long long temp = ldivisor; // Initialize a temporary variable to store divisor.
            long long multiple = 1;   // Initialize a multiple variable to track the number of times divisor can be subtracted.

            while (ldividend >= (temp << 1)) { // Use bitwise left shift to find multiples of divisor.
                temp <<= 1;      // Double the value of temp (divisor).
                multiple <<= 1;  // Double the multiple.
            }
            
            ldividend -= temp;     // Subtract the largest multiple of divisor from dividend.
            quotient += multiple;  // Add the corresponding multiple to the quotient.
        }

        return static_cast<int>(sign * quotient); // Apply the sign to the quotient and cast it to an int.
    }
};

// int main() {
//     Solution solution;
//     int dividend1 = 10, divisor1 = 3;
//     int result1 = solution.divide(dividend1, divisor1);
    
//     cout << "Result 1: " << result1 << endl;

//     int dividend2 = 7, divisor2 = -3;
//     int result2 = solution.divide(dividend2, divisor2);
    
//     cout << "Result 2: " << result2 << endl;

//     return 0;
// }
