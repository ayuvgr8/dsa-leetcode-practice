// #include <iostream>
// using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0; // Initialize the result to 0.

        // Iterate through each bit of the input integer.
        for (int i = 0; i < 32; ++i) {
            // Shift the result to the left by 1 to make room for the next bit.
            result <<= 1;
            // Extract the rightmost bit of the input integer and add it to the result.
            result |= (n & 1);
            // Shift the input integer to the right by 1 to get the next bit.
            n >>= 1;
        }

        return result;
    }
};

// int main() {
//     Solution solution;

//     uint32_t n1 = 43261596;
//     uint32_t result1 = solution.reverseBits(n1);
//     cout << "Result 1: " << result1 << endl;

//     uint32_t n2 = 4294967293;
//     uint32_t result2 = solution.reverseBits(n2);
//     cout << "Result 2: " << result2 << endl;

//     return 0;
// }
