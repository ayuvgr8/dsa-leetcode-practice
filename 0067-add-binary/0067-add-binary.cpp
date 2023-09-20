// #include <iostream>
// #include <string>
// using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result; // Initialize an empty string to store the result.
        int carry = 0; // Initialize a carry variable to 0.

        int i = a.size() - 1; // Initialize pointers to the last characters of both strings.
        int j = b.size() - 1;

        // Perform binary addition from right to left.
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry; // Initialize the sum with the carry.

            // Add the corresponding digits from 'a' and 'b' if they are not exhausted.
            if (i >= 0) {
                sum += a[i] - '0'; // Convert character to integer by subtracting '0'.
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // Calculate the carry for the next iteration.
            carry = sum / 2;

            // Append the current bit to the result string.
            result = to_string(sum % 2) + result;
        }

        return result;
    }
};

// int main() {
//     Solution solution;

//     string a1 = "11";
//     string b1 = "1";
//     string result1 = solution.addBinary(a1, b1);
//     cout << "Result 1: " << result1 << endl;

//     string a2 = "1010";
//     string b2 = "1011";
//     string result2 = solution.addBinary(a2, b2);
//     cout << "Result 2: " << result2 << endl;

//     return 0;
// }
