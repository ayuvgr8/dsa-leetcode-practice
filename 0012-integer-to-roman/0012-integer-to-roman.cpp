class Solution {
public:
    string intToRoman(int num) {
        // Arrays to store the Roman numeral symbols and their corresponding values.
        vector<string> romanSymbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string result = ""; // Initialize the result string to store the Roman numeral.
        
        // Iterate through the values and symbols.
        for (int i = 0; i < values.size(); i++) {
            // Repeatedly append the symbol while num is greater than or equal to the current value.
            while (num >= values[i]) {
                result += romanSymbols[i];
                num -= values[i];
            }
        }
        
        return result; // Return the final Roman numeral representation.
    }
};


// Here's how this code works:

// 1. We define two arrays, romanSymbols and values, to store the Roman numeral symbols and their corresponding values in descending order. For example, "M" corresponds to 1000, "CM" to 900, and so on.
// 2. We initialize an empty string result to store the Roman numeral representation.
// 3. We iterate through the values and romanSymbols arrays simultaneously. For each value-symbol pair, we do the following:
// a. While the given num is greater than or equal to the current values[i], we repeatedly append the corresponding romanSymbols[i] to the result string and subtract values[i] from num. This ensures that we use the largest possible Roman numeral symbols first.
// 4 Finally, we return the result string, which contains the Roman numeral representation of the given integer num.
// >>This solution effectively converts an integer into its Roman numeral representation following the rules and principles of Roman numerals.