class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7; // Define the modulo value to handle large numbers.

        long long count = 0; // Initialize a variable to store the count of homogenous substrings.
        int consecutive = 1; // Initialize a variable to track consecutive characters.

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                // If the current character is the same as the previous one, increment the consecutive count.
                consecutive++;
            } else {
                // If the current character is different, calculate the number of homogenous substrings
                // that can be formed with the consecutive characters and add it to the total count.
                count = (count + (static_cast<long long>(consecutive) * (consecutive + 1)) / 2) % MOD;


                // Reset the consecutive count for the new character.
                consecutive = 1;
            }
        }

        // Calculate the count for the last set of consecutive characters.
        count = (count + (static_cast<long long>(consecutive) * (consecutive + 1)) / 2) % MOD;


        return static_cast<int>(count);
    }
};
