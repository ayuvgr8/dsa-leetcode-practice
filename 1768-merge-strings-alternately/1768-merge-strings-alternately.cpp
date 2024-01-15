class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Initialize two indices i and j to traverse word1 and word2.
        int i = 0, j = 0;

        // Initialize an empty string to store the merged result.
        string ans = "";

        // Loop while there are characters left in both word1 and word2.
        while (i < word1.length() && j < word2.length()) {
            // Append the character at index i from word1 to the result string.
            ans += word1[i++];
            
            // Append the character at index j from word2 to the result string.
            ans += word2[j++];
        }

        // After the loop, check if there are remaining characters in word1.
        while (i < word1.length())
            // If yes, append the remaining characters from word1 to the result string.
            ans.push_back(word1[i++]);

        // Similarly, check if there are remaining characters in word2.
        while (j < word2.length())
            // If yes, append the remaining characters from word2 to the result string.
            ans.push_back(word2[j++]);

        // Return the final merged string.
        return ans;
    }
};
