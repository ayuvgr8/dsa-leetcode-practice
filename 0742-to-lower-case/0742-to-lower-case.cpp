class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            // Check if the character is an uppercase letter (ASCII value between 65 and 90).
            if (c >= 'A' && c <= 'Z') {
                // If it is, convert it to lowercase by adding 32 to its ASCII value.
                // 'A' (65) becomes 'a' (97), 'B' (66) becomes 'b' (98), and so on.
                c = c + 32;
            }
        }
        return s; // Return the modified string in lowercase.
    }
};
