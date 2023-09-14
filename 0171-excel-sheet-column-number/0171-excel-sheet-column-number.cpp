class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            int digit = c - 'A' + 1;  // Calculate the numerical value of the character.
            result = result * 26 + digit;  // Update the result by multiplying it by 26 and adding the digit.
        }
        return result;
    }
};