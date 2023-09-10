class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        
        // Iterate through the digits in reverse order
        for (int i = n - 1; i >= 0; --i) {
            // Increment the current digit by 1
            digits[i]++;
            
            // If the digit becomes 10 after increment, set it to 0 and carry 1 to the next digit
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                // If the digit doesn't become 10, no need to carry further, so we can return the result
                return digits;
            }
        }
        
        // If we reach here, it means all digits became 0, so we need to add a new leading 1
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

// int main() {
//     Solution solution;

//     std::vector<int> digits = {1, 2, 3};
//     std::vector<int> result = solution.plusOne(digits);

//     std::cout << "Result: [";
//     for (int i = 0; i < result.size(); ++i) {
//         std::cout << result[i];
//         if (i < result.size() - 1) {
//             std::cout << ", ";
//         }
//     }
//     std::cout << "]" << std::endl;

//     return 0;
// }